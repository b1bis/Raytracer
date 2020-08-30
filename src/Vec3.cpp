#include "Vec3.hpp"

inline Vec3 Vec3::operator-() const
{
	return Vec3(-m_x, -m_y, -m_z);
}

inline Vec3& Vec3::operator+=(const Vec3& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	m_z += rhs.m_z;
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	m_z -= rhs.m_z;
	return *this;
}

inline Vec3& Vec3::operator*=(double t)
{
	m_x *= t;
	m_y *= t;
	m_z *= t;
	return *this;
}

inline Vec3& Vec3::operator/=(double t)
{
	m_x /= t;
	m_y /= t;
	m_z /= t;
	return *this;
}

double Vec3::SquaredLenght() const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

double Vec3::Lenght() const
{
	return std::sqrt(SquaredLenght());
}

void Vec3::Normalize()
{
	double magnitude = Lenght();
	if (magnitude != 0)
	{
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
	}
}

double Vec3::DotProduct(const Vec3& v1, const Vec3& v2)
{
	return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}

Vec3 Vec3::CrossProduct(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.m_y * v2.m_z - v1.m_z * v2.m_y, v1.m_z * v2.m_x - v1.m_x * v2.m_z, v1.m_x * v2.m_y - v1.m_y * v2.m_x);
}

Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY(), lhs.GetZ() + rhs.GetZ());
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY(), lhs.GetZ() - rhs.GetZ());
}

Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.GetX() * rhs.GetX(), lhs.GetY() * rhs.GetY(), lhs.GetZ() * rhs.GetZ());
}

Vec3 operator*(double t, const Vec3& rhs)
{
	return Vec3(rhs.GetX() * t, rhs.GetY() * t, rhs.GetZ() * t);
}

Vec3 operator*(const Vec3& lhs, double t)
{
	return t * lhs;
}

Vec3 operator/(double t, const Vec3& rhs)
{
	return Vec3(rhs.GetX() / t, rhs.GetY() / t, rhs.GetZ() / t);
}

Vec3 operator/(const Vec3& lhs, double t)
{
	return t / lhs;
}
