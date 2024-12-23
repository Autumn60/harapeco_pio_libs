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

#ifndef ROBOMASTER_MOTOR_DRIVER_LIB__HANDLER_HPP_
#define ROBOMASTER_MOTOR_DRIVER_LIB__HANDLER_HPP_

#include "motor.hpp"

#include <FlexCAN.h>

namespace robomaster_motor_driver_lib
{
class Handler
{
public:
  explicit Handler(FlexCAN * can);
  ~Handler() = default;

  void register_motor(Motor * motor);
  void update();

private:
  void read();
  void write(bool part);

  FlexCAN * can_;
  Motor * motors_[8];

  const uint32_t kDelayRead = 10;
  const uint32_t kIdBase = 0x201;

  const uint32_t kDelayWrite = 1;
  const uint32_t kIdWriteLow = 0x200;
  const uint32_t kIdWriteHigh = 0x1ff;
};
}  // namespace robomaster_motor_driver_lib

#endif  // ROBOMASTER_MOTOR_DRIVER_LIB__HANDLER_HPP_
