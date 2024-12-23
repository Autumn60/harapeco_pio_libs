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

#include "robomaster_motor_driver_lib/motor.hpp"

#include <Arduino.h>

namespace robomaster_motor_driver_lib
{
Motor::Motor(int id) : id_(id), round_count_(0), angle_bit_last_(-1)
{
}

void Motor::set_target_current(double target_current)
{
  target_current_bit_ =
    constrain(static_cast<int>(target_current * kCurrentCoeff), -kCurrentBitMax, kCurrentBitMax);
}

double Motor::get_raw_angle() const
{
  return angle_raw_;
}

double Motor::get_incremental_angle() const
{
  return angle_incremental_;
}

int Motor::get_round_count() const
{
  return round_count_;
}

double Motor::get_velocity() const
{
  return velocity_;
}

double Motor::get_current() const
{
  return current_;
}

int Motor::get_temperature() const
{
  return temperature_;
}

int Motor::get_target_current_bit() const
{
  return target_current_bit_;
}

void Motor::update_angle(int angle_bit)
{
  angle_raw_ = angle_bit * kAngleCoeff;

  if (angle_bit_last_ == -1) {
    angle_incremental_ = 0.0;
    angle_bit_last_ = angle_bit;
  }

  int angle_bit_diff = angle_bit - angle_bit_last_;
  int round_diff = (angle_bit_diff < -4096) - (angle_bit_diff > 4096);
  round_count_ += round_diff;
  angle_incremental_ = (M_PI * 2.0 * round_count_ + angle_raw_) * kReductionRatioInv;

  angle_bit_last_ = angle_bit;
}

void Motor::update_velocity(int velocity_bit)
{
  velocity_ = velocity_bit * kVelocityCoeff * kReductionRatioInv;
}

void Motor::update_current(int current_bit)
{
  current_ = current_bit * kCurrentCoeffInv;
}

void Motor::update_temperature(int temperature)
{
  temperature_ = temperature;
}
}  // namespace robomaster_motor_driver_lib
