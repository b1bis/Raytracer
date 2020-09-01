#pragma once

#include <iostream>
#include <algorithm>

struct Color
{
	Color() = default;
	Color(double r, double g, double b) : r {r}, g {g}, b {b} {}

	std::ostream& WritePPM(std::ostream& out);
	std::ostream& WritePPM(std::ostream& out, int sample);

	Color& operator+=(const Color& rhs);
	Color& operator-=(const Color& rhs);
	Color& operator*=(double t);
	Color& operator/=(double t);

	double r = 0, g = 0, b = 0;

};

Color operator+(const Color& lhs, const Color& rhs);
Color operator-(const Color& lhs, const Color& rhs);
Color operator*(const Color& lhs, const Color& rhs);

Color operator*(double t, const Color& rhs);
Color operator*(const Color& lhs, double t);
Color operator/(double t, const Color& rhs);
Color operator/(const Color& lhs, double t);