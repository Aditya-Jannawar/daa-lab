#include <bits/stdc++.h>
using namespace std;
long long modExp(long long base, long long exponent, long long modulus) {
 int result = 1;
 base = base % modulus;
 while (exponent > 0) {
 if (exponent & 1) {
 result = (result * base) % modulus;
 }
 exponent = exponent >> 1;
 base = (base * base) % modulus;
 }
 return result;
}
int main() {
 int mod = (int)1e9+7;
 int base, exponent;
 cin >> base >> exponent;
 cout << modExp(base, exponent, mod);
 return 0;
}
