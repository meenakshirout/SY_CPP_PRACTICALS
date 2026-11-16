#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
};

class Rectangle : public Shape
{
public:
    void area()
    {
        int l = 5, b = 4;
        cout << "Area of Rectangle: " << l * b << endl;
    }
};

class Circle : public Shape
{
public:
    void area()
    {
        int r = 3;
        cout << "Area of Circle: " << 3.14 * r * r << endl;
    }
};

class Triangle : public Shape
{
public:
    void area()
    {
        int b = 6, h = 4;
        cout << "Area of Triangle: " << 0.5 * b * h << endl;
    }
};

int main()
{
    Rectangle r;
    Circle c;
    Triangle t;

    Shape *s;

    s = &r;
    s->area();

    s = &c;
    s->area();

    s = &t;
    s->area();

    return 0;
}
