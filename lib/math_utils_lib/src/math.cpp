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

#include "math_utils_lib/math.hpp"

#include <Arduino.h>

namespace math_utils_lib
{
double Math::lerp(double min_val, double max_val, double t)
{
  t = constrain(t, 0.0, 1.0);
  return min_val + t * (max_val - min_val);
}

double Math::lerp_unclamped(double min_val, double max_val, double t)
{
  return min_val + t * (max_val - min_val);
}

double Math::inverse_lerp(double min_val, double max_val, double val)
{
  val = constrain(val, min_val, max_val);
  return min_val != max_val ? (val - min_val) / (max_val - min_val) : 0.0;
}

int Math::round(double val)
{
  if (val < 0.0) {
    return static_cast<int>(val - 0.5);
  } else {
    return static_cast<int>(val + 0.5);
  }
}

double Math::sign(double val)
{
  return val == 0.0 ? 0.0 : val < 0.0 ? -1.0 : 1.0;
}

template <typename First>
First Math::max(First first)
{
  return first;
}

template <typename First, typename... Rest>
First Math::max(First first, Rest... rest)
{
  return first > max(rest...) ? first : max(rest...);
}

template <typename First>
First Math::min(First first)
{
  return first;
}

template <typename First, typename... Rest>
First Math::min(First first, Rest... rest)
{
  return first < min(rest...) ? first : min(rest...);
}

bool Math::is_even(int val)
{
  return val % 2 == 0;
}

bool Math::is_odd(int val)
{
  return val % 2 != 0;
}

bool Math::is_power_of_two(int val)
{
  return val > 0 && (val & (val - 1)) == 0;
}
}  // namespace math_utils_lib
