#include "linear.h"

vect2f operator+(const vect2f &v1, const vect2f &v2)
{
	return { v1.x + v2.x, v1.y + v2.y };
}

vect2f operator*(const float &a, const vect2f &v)
{
	return { a * v.x, a * v.y };
}

vect2f circle(vect2f r0, float R, int i, int N)
{
	return { r0.x + R*cos(2.f * M_PI / float(N) * i), r0.y + R*sin(2.f * M_PI / float(N) * i) } ;
}