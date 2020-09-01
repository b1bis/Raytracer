#include "Vec3.hpp"

Vec3 Vec3::Random(double min, double max)
{
	static std::default_random_engine engine(static_cast<unsigned>(std::time(nullptr)));
	std::uniform_real_distribution<double> dis(min, max);
	return Vec3(dis(engine), dis(engine), dis(engine));
}

Vec3 Vec3::RandomUnitVector()
{
	static std::default_random_engine engine(static_cast<unsigned>(std::time(nullptr)));
	std::uniform_real_distribution<double> dis1(0, 2 * Constants::Pi);
	double a = dis1(engine);
	std::uniform_real_distribution<double> dis2(-1, 1);
	double z = dis2(engine);
	double r = std::sqrt(1 - z * z);
	return Vec3{ r * std::cos(a), r * std::sin(a), z };
}

Vec3 Vec3::operator-() const
{
	return Vec3(-m_x, -m_y, -m_z);
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	m_z += rhs.m_z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	m_z -= rhs.m_z;
	return *this;
}

Vec3& Vec3::operator*=(double t)
{
	m_x *= t;
	m_y *= t;
	m_z *= t;
	return *this;
}

Vec3& Vec3::operator/=(double t)
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
