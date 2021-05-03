#pragma once

class Point
{
public:
	float x;
	float y;

	Point(float x, float y) :x{ x }, y{ y }
	{ }

	bool operator > (const Point& rhs) const
	{
		return (x + y) > (rhs.x + rhs.y);
	}

	bool operator < (const Point& rhs) const
	{
		return (x + y) < (rhs.x + rhs.y);
	}
};

ostream& operator << (ostream& output, const Point& p)
{
	output << "(" << p.x << "," << p.y << ")";
	return output;
}
