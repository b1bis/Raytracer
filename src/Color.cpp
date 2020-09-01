#include "Color.hpp"

std::ostream& Color::WritePPM(std::ostream& out)
{
	out << static_cast<int>(256 * std::clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * std::clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * std::clamp(b, 0.0, 0.999));
	return out;
}

std::ostream& Color::WritePPM(std::ostream& out, int sample)
{
	r = std::sqrt(r / sample);
	g = std::sqrt(g / sample);
	b = std::sqrt(b / sample);
	return WritePPM(out);
}

Color& Color::operator+=(const Color& rhs)
{
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	return *this;
}

Color& Color::operator-=(const Color& rhs)
{
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	return *this;
}

Color& Color::operator*=(double t)
{
	r *= t;
	g *= t;
	b *= t;
	return *this;
}

Color& Color::operator/=(double t)
{
	r /= t;
	g /= t;
	b /= t;
	return *this;
}

Color operator+(const Color& lhs, const Color& rhs)
{
	return Color(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b);
}

Color operator-(const Color& lhs, const Color& rhs)
{
	return Color(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b);
}

Color operator*(const Color& lhs, const Color& rhs)
{
	return Color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b);
}

Color operator*(double t, const Color& rhs)
{
	return Color(t * rhs.r, t * rhs.g, t * rhs.b);
}

Color operator*(const Color& lhs, double t)
{
	return t * lhs;
}

Color operator/(double t, const Color& rhs)
{
	return Color(t / rhs.r, t / rhs.g, t / rhs.b);
}

Color operator/(const Color& lhs, double t)
{
	return t / lhs;
}
