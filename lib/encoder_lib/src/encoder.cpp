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

#include "encoder_lib/encoder.hpp"

namespace encoder_lib
{
Encoder::Encoder(int pin_a, int pin_b, int ppr)
: encoder_(pin_a, pin_b), ppr_inv_(1.0 / ppr), pulse_(0), is_initialized_(false)
{
}

void Encoder::update()
{
  pulse_ = encoder_.read();

  if (!is_initialized_) {
    pulse_diff_ = 0;
    pulse_prev_ = pulse_;
    is_initialized_ = true;
    return;
  }

  pulse_diff_ = pulse_ - pulse_prev_;
  pulse_prev_ = pulse_;
}
}  // namespace encoder_lib
