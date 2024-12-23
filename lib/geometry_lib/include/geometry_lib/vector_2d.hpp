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

#ifndef GEOMETRY_LIB__VECTOR_2D_HPP_
#define GEOMETRY_LIB__VECTOR_2D_HPP_

namespace geometry_lib
{
class Vector2D
{
  friend class Vector2D;

public:
  Vector2D();
  Vector2D(double x, double y);
  ~Vector2D() = default;

  Vector2D operator+(const Vector2D & rhs) const;
  Vector2D operator-(const Vector2D & rhs) const;
  Vector2D operator*(double scalar) const;
  Vector2D operator/(double scalar) const;
  Vector2D & operator+=(const Vector2D & rhs);
  Vector2D & operator-=(const Vector2D & rhs);
  Vector2D & operator*=(double scalar);
  Vector2D & operator/=(double scalar);
  bool operator==(const Vector2D & rhs) const;
  bool operator!=(const Vector2D & rhs) const;

  double dot(const Vector2D & rhs) const;
  double cross(const Vector2D & rhs) const;
  Vector2D get_rotated(double angle) const;
  Vector2D get_normalized() const;
  double length() const;
  double length_squared() const;
  double angle() const;

  double x;
  double y;
};  // class Vector2D
}  // namespace geometry_lib

#endif  // GEOMETRY_LIB__VECTOR_2D_HPP_
