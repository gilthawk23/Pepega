#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class bird
{
private:
    int x1, x2, y1, y2;
    float speed, distance;

public:
    bird()
    {
        cout << "Enter x1 y1:";
        cin >> x1 >> y1;
        cout << "Enter x2 y2:";
        cin >> x2 >> y2;
        cout << "Enter speed:";
        cin >> speed;
    };

    float findDistance()
    {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    float findTime()
    {
        return findDistance() / speed;
    }
};

int main()
{
    bird a;
    cout << "distance between 2 dots:" << a.findDistance() << endl;
    cout << "time:" << a.findTime() << endl;
}
