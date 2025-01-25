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

#include "cytron_motor_driver_lib/motor.hpp"

#include <Arduino.h>

namespace cytron_motor_driver_lib
{
Motor::Motor(int magnitude_pin, int direction_pin)
: magnitude_pin_(magnitude_pin), direction_pin_(direction_pin)
{
  analogWriteFrequency(magnitude_pin_, 20000);
  pinMode(direction_pin_, OUTPUT);
  stop();
}

void Motor::drive(double power)
{
  digitalWrite(direction_pin_, power < 0 ? HIGH : LOW);
  analogWrite(magnitude_pin_, abs(power) * 255);
}

void Motor::stop()
{
  digitalWrite(direction_pin_, LOW);
  analogWrite(magnitude_pin_, 0);
}
}  // namespace cytron_motor_driver_lib
