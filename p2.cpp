#include <iostream>
using namespace std;

template <typename T, int mul = 0>
class myclass
{

private:
    T x;

public:
    myclass(T y)
    {
        if (mul)
        {
            this->x = y * (T)mul;
        }
        else
        {
            this->x = y;
        }
    }

    T getx(){
        return x;
    }
};

template <>
class myclass<int, 0>
{
private:
    int x;

public:
    myclass(int y)
    {
        this->x = y * 5;
    }
    int getx(){
        return x;
    }
};
int main()
{
    myclass<double> d1(1.1);
    myclass<double, 2> d2(1.1);
    myclass<double, 3> d3(1.1);
    cout << d1.getx() << " " << d2.getx() << " " << d3.getx()
         << "\n";
    myclass<int, 4> i1(5);
    myclass<int> i2(5);
    cout << i1.getx() << " " << i2.getx();
    return 0;
}
