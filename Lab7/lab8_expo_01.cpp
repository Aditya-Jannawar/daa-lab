#include <iostream>

using namespace std;

int pow(int x, unsigned int n)
{
    int pow = 1;
    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }
    return pow;
}

int pownew(int x, unsigned int n)
{
    if (n == 0) {
        return 1;
    }
    int y = pownew(x, n/2);
    if (n % 2 == 0) {
        return y * y;
    } else {
        return x * y * y;
    }
}

int main()
{
    // cout << "pow is " << pow(2, 3) << endl;
    cout << "pownew is " << pownew(2, 3) << endl;
    return 0;
}
