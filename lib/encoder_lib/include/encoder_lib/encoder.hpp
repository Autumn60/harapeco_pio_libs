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

#ifndef ENCODER_LIB__ENCODER_HPP_
#define ENCODER_LIB__ENCODER_HPP_

#include <Encoder.h>

namespace encoder_lib
{
using RawEncoder = Encoder;

class Encoder
{
public:
  explicit Encoder(int pin_a, int pin_b, int pulse_per_revolution);
  ~Encoder() = default;

  void update();
  int32_t get_pulse() const { return pulse_; }
  int32_t get_pulse_diff() const { return pulse_diff_; }
  bool is_initialized() const { return is_initialized_; }

private:
  RawEncoder encoder_;

  double ppr_inv_;

  int32_t pulse_;
  int32_t pulse_prev_;
  int32_t pulse_diff_;

  bool is_initialized_;
};

}  // namespace encoder_lib

#endif  // ENCODER_LIB__ENCODER_HPP_
