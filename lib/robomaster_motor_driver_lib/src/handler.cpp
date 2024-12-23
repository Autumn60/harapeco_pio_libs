// Copyright 2024 Akiro Harada
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "robomaster_motor_driver_lib/handler.hpp"

namespace robomaster_motor_driver_lib
{
Handler::Handler(FlexCAN * can) : can_(can)
{
}

void Handler::register_motor(Motor * motor)
{
  int id = motor->get_id();
  if (id < 1 || id > 8) return;
  motors_[motor->get_id() - 1] = motor;
}

void Handler::update()
{
  read();
  delay(kDelayRead);
  write(0);
  write(1);
}

void Handler::read()
{
  while (can_->available()) {
    CAN_message_t msg;
    can_->read(msg);
    Motor * motor = motors_[msg.id - kIdBase];
    if (motor == nullptr) continue;
    motor->update_angle((msg.buf[1] | msg.buf[0] << 8));
    motor->update_velocity(((int16_t)(msg.buf[2] << 8) + msg.buf[3]));
    motor->update_current(((int16_t)(msg.buf[4] << 8) + msg.buf[5]));
    motor->update_temperature(msg.buf[6]);
  }
}

void Handler::write(bool part)
{
  CAN_message_t msg;
  msg.ext = 0;
  msg.len = 8;
  msg.id = part ? kIdWriteHigh : kIdWriteLow;
  int offset = part ? 4 : 0;
  bool pub_check = false;
  for (int i = 0; i < 4; i++) {
    Motor * motor = motors_[i + offset];
    if (motor == nullptr) continue;
    delay(kDelayWrite);
    int data = motor->get_target_current_bit();
    msg.buf[2 * i] = highByte(data);
    msg.buf[2 * i + 1] = lowByte(data);
    pub_check = true;
  }
  if (!pub_check) return;
  can_->write(msg);
}

}  // namespace robomaster_motor_driver_lib
