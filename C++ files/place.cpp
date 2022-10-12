#include <iostream>
#include <math.h>
using namespace std;
class bird
{
    int x1, y1, x2, y2, b, a;
    float t, v1, v2, d, d1, b1, a1, xk, yk;

public:
    bird()
    {
        cout << "enter x1, y1, v1\n";
        cin >> x1 >> y1 >> v1;

        cout << "enter x2, y2, v2\n";
        cin >> x2 >> y2 >> v2;
    };
    void calc()
    {
        d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        t = d / (v1 + v2);
        d1 = v1 * t;
        b = x2 - x1;
        a = y2 - y1;

        b1 = b * d1 / d;
        a1 = a * d1 / d;

        xk = x1 + b1;
        yk = y1 + a1;
    }

    void printCoordinates()
    {
        cout << "x:" << xk << "  y:" << yk << "  time:" << t <<  endl;
    }
};

int main()
{
    bird b;
    b.calc();
    b.printCoordinates();
}