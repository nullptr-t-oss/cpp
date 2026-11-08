#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main([[maybe_unused]] int argc ,[[maybe_unused]] char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    double x{};

    /*
     * freopen("input.txt", "r", stdin);
     * freopen("output.txt", "w", stdout);
     */

    // int32_t a = 2;
    // printf("%.9f\n", x);

    /*
     * since some floating point numbers cant be represented in binary
     * use this to compare two floats assuming their difference
     * is small enough (ε = 10−9)
     * 
     * if (abs(a - b) < 1e-9) {
     *  // a and b are equal
     * }
     */

    // upper bound for harmonic sum (summatin of 1/x from 1 to n) is log base 2 (n) + 1

    cout << (bool)cin;

    cout << '\n' << x;

    return 0;
}
