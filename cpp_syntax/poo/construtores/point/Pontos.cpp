#include "Point.h"

int main()
{
	Point p;
    Point a {50, 20};

	p.MoveTo(10, 20);
	p.Translate(2, 5);
    p.print();

    a.Translate(4, 8);
    a.print();
}