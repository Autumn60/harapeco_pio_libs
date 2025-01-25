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

#ifndef CYTRON_MOTOR_DRIVER_LIB__MOTOR_HPP_
#define CYTRON_MOTOR_DRIVER_LIB__MOTOR_HPP_

namespace cytron_motor_driver_lib
{
class Motor
{
public:
  /// @brief Construct a new Motor object
  /// @param magnitude_pin Number of the analog pin connected to the motor's magnitude input
  /// @param direction_pin Number of the digital pin connected to the motor's direction input
  Motor(int magnitude_pin, int direction_pin);
  ~Motor() = default;

  /// @brief Drive the motor at a given power
  /// @param power Power to drive the motor at, in the range [-1.0, 1.0]
  void drive(double power);

  /// @brief Stop the motor
  void stop();

private:
  int magnitude_pin_;
  int direction_pin_;
};  // class Motor
}  // namespace cytron_motor_driver_lib

#endif  // CYTRON_MOTOR_DRIVER_LIB__MOTOR_HPP_
