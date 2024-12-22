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

#ifndef MATH_UTILS_LIB__MATH_HPP_
#define MATH_UTILS_LIB__MATH_HPP_

#include <algorithm>

namespace math_utils_lib
{
class Math
{
public:
  static double lerp(double min_val, double max_val, double t);
  static double lerp_unclamped(double min_val, double max_val, double t);
  static double inverse_lerp(double min_val, double max_val, double val);
  static int round(double val);
  static double sign(double val);

  template <typename First>
  static First max(First first);
  template <typename First, typename... Rest>
  static First max(First first, Rest... rest);

  template <typename First>
  static First min(First first);
  template <typename First, typename... Rest>
  static First min(First first, Rest... rest);

  static bool is_even(int val);
  static bool is_odd(int val);
  static bool is_power_of_two(int val);
};  // class Math
}  // namespace math_utils_lib

#endif  // MATH_UTILS_LIB__MATH_HPP_
