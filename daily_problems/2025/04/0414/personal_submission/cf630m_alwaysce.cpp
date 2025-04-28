#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 x;
    cin >> x;
    x = x % 360 + 3 * 360;

    int diff = 360, time = -1;

    for (int i = 0; i < 4; i++) {
        int v = (x - i * 90) % 360;
        v = min(v, 360 - v);
        if (v < diff) {
            diff = v;
            time = i;
        }
    }

    cout << time << '\n';
    return 0;
}
