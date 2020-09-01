#pragma once

#include <cmath>
#include <random>
#include <ctime>

#include "Constants.hpp"

class Vec3
{
public:
	Vec3() = default;
	Vec3(double x, double y, double z) : m_x {x}, m_y {y}, m_z{z} {}
	static Vec3 Zero() { return Vec3(0., 0., 0.); }

	static Vec3 Random(double min, double max);
	static Vec3 Random() { return Vec3::Random(0.0, 1.0); }

	static Vec3 RandomUnitVector();

	double GetX() const { return m_x; }
	double GetY() const { return m_y; }
	double GetZ() const { return m_z; }

	void SetX(double x) { m_x = x; }
	void SetY(double y) { m_y = y; }
	void SetZ(double z) { m_z = z; }

	Vec3 operator-() const;
	Vec3& operator+=(const Vec3& rhs);
	Vec3& operator-=(const Vec3& rhs);
	Vec3& operator*=(double t);
	Vec3& operator/=(double t);

	double SquaredLenght() const;
	double Lenght() const;

	void Normalize();

	static double DotProduct(const Vec3& v1, const Vec3& v2);
	double DotProduct(const Vec3& v) { return Vec3::DotProduct(*this, v); }

	static Vec3 CrossProduct(const Vec3& v1, const Vec3& v2);

private:
	double m_x = 0.;
	double m_y = 0.;
	double m_z = 0.;
};


Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
Vec3 operator*(const Vec3& lhs, const Vec3& rhs);

Vec3 operator*(double t, const Vec3& rhs);
Vec3 operator*(const Vec3& lhs, double t);
Vec3 operator/(double t, const Vec3& rhs);
Vec3 operator/(const Vec3& lhs, double t);