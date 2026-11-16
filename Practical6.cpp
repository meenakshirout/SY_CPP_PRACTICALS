#include <iostream>
using namespace std;

// Function Overloading
void add(int a, int b)
{
    cout << "Integer Addition: " << a + b << endl;
}

void add(float a, float b)
{
    cout << "Float Addition: " << a + b << endl;
}

class Complex
{
public:
    int real, imag;

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Operator Overloading
    Complex operator+(Complex c)
    {
        Complex temp(0, 0);
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    add(10, 20);
    add(2.5f, 3.5f);

    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;

    cout << "Complex Number Addition: ";
    c3.display();

    return 0;
}
