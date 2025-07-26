#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n;
    cin >> n;

    /*
    */
    i64 dp0 = 0, dp1 = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            dp0 = (dp0 + dp1 + 1) % mod;
        } else {
            dp1 = (dp0 + dp1 + 1) % mod;
        }
    }

    cout << (dp0 + dp1) % mod << "\n";
    return 0;
}
