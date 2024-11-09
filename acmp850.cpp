#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int p, m;
    cin >> p >> m;
    int minp = p / 2 + p % 2;
    int minm = m / 2 + m % 2;
    int mino = minm;
    if (minp > minm) {
        mino = minp;
    }
    int maxm = m;
    int maxp = p;
    int maxo = maxm;
    if (maxp < maxm) {
        maxo = maxp;
    }
    cout << mino << " " << maxo << " ";

    return 0;
}