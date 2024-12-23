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

#ifndef ROBOMASTER_MOTOR_DRIVER_LIB__MOTOR_HPP_
#define ROBOMASTER_MOTOR_DRIVER_LIB__MOTOR_HPP_

#include "handler.hpp"

namespace robomaster_motor_driver_lib
{
class Motor
{
  friend class Handler;

public:
  explicit Motor(int id);
  ~Motor() = default;

  int get_id() const;

  void set_target_current(double target_current);

  double get_raw_angle() const;
  double get_incremental_angle() const;
  int get_round_count() const;

  double get_velocity() const;

  double get_current() const;

  int get_temperature() const;

private:
  int get_target_current_bit() const;
  void update_angle(int angle_bit);
  void update_velocity(int velocity_bit);
  void update_current(int current_bit);
  void update_temperature(int temperature);

  int id_;

  const double kReductionRatio = 3591.0 / 187.0;
  const double kReductionRatioInv = 1.0 / kReductionRatio;

  int target_current_bit_;
  const double kCurrentCoeff = 16384.0 / 20.0;
  const int kCurrentBitMax = 16384;

  double angle_raw_;
  double angle_incremental_;
  int round_count_;
  int angle_bit_last_;
  const double kAngleCoeff = 2.0 * M_PI / 8192.0;

  double velocity_;
  const double kVelocityCoeff = 2.0 * M_PI / 60.0;

  double current_;
  const double kCurrentCoeffInv = 20.0 / 16384.0;

  int temperature_;
};
}  // namespace robomaster_motor_driver_lib

#endif  // ROBOMASTER_MOTOR_DRIVER_LIB__MOTOR_HPP_
