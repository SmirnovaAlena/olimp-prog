#include <iostream>

using namespace std;

int main()
{
    int a, b, x, y, c;

    cin >> a >> b >> x >> y >> c;
    string c1 = "white";
    string c0 = "black";
    if (a * b % 2 == 0) {
        cout << "equal";

    }
    else {
        if ((x + y) % 2 == 0) {
            if (c == 0) {
                cout << c0;
            }
            if (c == 1) {
                cout << c1;
            }
        }
        else {
            if (c == 1) {
                cout << c0;
            }
            if (c == 0) {
                cout << c1;
            }

        }
    }
    return 0;
}