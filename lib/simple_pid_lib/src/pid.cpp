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

#include "simple_pid_lib/pid.hpp"

#include <Arduino.h>

namespace simple_pid_lib
{
PID::PID(double k_p, double k_i, double k_d, double k_b, double n, double t)
: time_last_(0), i_(0.0), d_(0.0), error_last_(0.0), anti_windup_last_(0.0), output_(0.0)
{
  set_gains(k_p, k_i, k_d, k_b, n, t);
}

void PID::update(double error)
{
  uint32_t time_now = micros();
  double dt = (time_now - time_last_) * 1e-6;
  if (dt < t_) return;

  double p = k_p_ * error;
  i_ = k_i_ * (error + error_last_);
  d_ = k_f_ * d_ + k_d_ * (error - error_last_);

  double u = p + i_ + d_;
  double anti_windup = constrain(u, output_min_, output_max_) - u;
  d_ += k_b_ * (anti_windup + anti_windup_last_);

  output_ = constrain(p + i_ + d_, output_min_, output_max_);
  error_last_ = error;
  anti_windup_last_ = anti_windup;
  time_last_ = time_now;
}

double PID::get_output() const
{
  return output_;
}

void PID::reset_integral()
{
  i_ = 0.0;
  anti_windup_last_ = 0.0;
}

void PID::set_gains(double k_p, double k_i, double k_d, double k_b, double n, double t)
{
  t_ = t;
  k_p_ = k_p;
  k_i_ = 0.5 * k_i * t;
  k_d_ = (2 * k_d * n) / (2 + n * t);
  k_b_ = 0.5 * k_b * t;
  k_f_ = (2 - n * t) / (2 + n * t);

  i_ = 0.0;
  d_ = 0.0;
  error_last_ = 0.0;
  time_last_ = micros();
}

void PID::set_saturation(double min, double max)
{
  output_min_ = min;
  output_max_ = max;
}
}  // namespace simple_pid_lib
