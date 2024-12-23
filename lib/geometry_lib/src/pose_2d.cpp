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

#include "geometry_lib/pose_2d.hpp"

namespace geometry_lib
{
Pose2D::Pose2D() : position(Vector2D()), angle(0.0)
{
}

Pose2D::Pose2D(Vector2D position, double angle) : position(position), angle(angle)
{
}

Pose2D::Pose2D(double x, double y, double angle) : position(Vector2D(x, y)), angle(angle)
{
}

bool Pose2D::operator==(const Pose2D & rhs) const
{
  return position == rhs.position && angle == rhs.angle;
}

bool Pose2D::operator!=(const Pose2D & rhs) const
{
  return !(*this == rhs);
}

}  // namespace geometry_lib
