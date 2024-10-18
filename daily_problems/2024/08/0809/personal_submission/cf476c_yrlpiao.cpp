#include <iostream>
using namespace std;

int mod = 1e9 + 7;

signed main() {
    int a, b; cin >> a >> b;
    int x = 1LL * b * (b - 1) / 2 % mod;
    int y = (1LL * a * (a + 1) / 2 % mod * b % mod + a) % mod;
    cout << 1LL * x * y % mod;
}
