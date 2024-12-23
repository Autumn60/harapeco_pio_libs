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

#ifndef GEOMETRY_LIB__POSE_2D_HPP_
#define GEOMETRY_LIB__POSE_2D_HPP_

#include "vector_2d.hpp"

namespace geometry_lib
{
class Pose2D
{
  friend class Pose2D;

public:
  Pose2D();
  Pose2D(Vector2D position, double angle);
  Pose2D(double x, double y, double angle);
  ~Pose2D() = default;

  bool operator==(const Pose2D & rhs) const;
  bool operator!=(const Pose2D & rhs) const;

  Vector2D position;
  double angle;
};  // class Pose2D
}  // namespace geometry_lib

#endif  // GEOMETRY_LIB__POSE_2D_HPP_
