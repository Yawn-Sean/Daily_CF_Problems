#include <iostream>
#include <cmath>
using namespace std;
#define int long long

int yrlpSolve() {
    int a, b; scanf("%lld%lld", &a, &b);
    int x = cbrt(a * b);
    if (x * x * x != a * b) cout << "no" << endl;
    else if (a % x == 0 && b % x == 0) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
