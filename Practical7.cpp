#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T x)
    {
        arr[++top] = x;
        cout << "pushed: " << x << endl;
    }

    void pop()
    {
        cout << "element popped: " << arr[top] << endl;
        top--;
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();

    return 0;
}
