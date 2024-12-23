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

#include "geometry_lib/vector_2d.hpp"

#include <cmath>

namespace geometry_lib
{
Vector2D::Vector2D() : x(0.0), y(0.0)
{
}

Vector2D::Vector2D(double x, double y) : x(x), y(y)
{
}

Vector2D Vector2D::operator+(const Vector2D & rhs) const
{
  return Vector2D(x + rhs.x, y + rhs.y);
}

Vector2D Vector2D::operator-(const Vector2D & rhs) const
{
  return Vector2D(x - rhs.x, y - rhs.y);
}

Vector2D Vector2D::operator*(double scalar) const
{
  return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const
{
  return Vector2D(x / scalar, y / scalar);
}

Vector2D & Vector2D::operator+=(const Vector2D & rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Vector2D & Vector2D::operator-=(const Vector2D & rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

Vector2D & Vector2D::operator*=(double scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

Vector2D & Vector2D::operator/=(double scalar)
{
  x /= scalar;
  y /= scalar;
  return *this;
}

bool Vector2D::operator==(const Vector2D & rhs) const
{
  return x == rhs.x && y == rhs.y;
}

bool Vector2D::operator!=(const Vector2D & rhs) const
{
  return x != rhs.x || y != rhs.y;
}

double Vector2D::dot(const Vector2D & rhs) const
{
  return x * rhs.x + y * rhs.y;
}

double Vector2D::cross(const Vector2D & rhs) const
{
  return x * rhs.y - y * rhs.x;
}

Vector2D Vector2D::get_rotated(double angle) const
{
  double cos_angle = cos(angle);
  double sin_angle = sin(angle);
  return Vector2D(x * cos_angle - y * sin_angle, x * sin_angle + y * cos_angle);
}

Vector2D Vector2D::get_normalized() const
{
  double len = length();
  return Vector2D(x / len, y / len);
}

double Vector2D::length() const
{
  return sqrt(length_squared());
}

double Vector2D::length_squared() const
{
  return x * x + y * y;
}

double Vector2D::angle() const
{
  return atan2(y, x);
}

}  // namespace geometry_lib
