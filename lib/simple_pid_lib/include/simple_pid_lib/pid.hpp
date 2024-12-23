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

#ifndef SIMPLE_PID_LIB__PID_HPP_
#define SIMPLE_PID_LIB__PID_HPP_

namespace simple_pid_lib
{
class PID
{
public:
  PID(double k_p, double k_i, double k_d, double k_b, double n, double t);
  ~PID() = default;
  void update(double error);
  double get_output() const;
  void reset_integral();
  void set_gains(double k_p, double k_i, double k_d, double k_b, double n, double t);
  void set_saturation(double min, double max);

private:
  double k_p_, k_i_, k_d_, k_b_, k_f_, t_;
  uint32_t time_last_;
  double i_, d_;
  double error_last_;
  double anti_windup_last_;
  double output_;
  double output_min_ = -1e6;
  double output_max_ = 1e6;
};

}  // namespace simple_pid_lib

#endif  // SIMPLE_PID_LIB__PID_HPP_
