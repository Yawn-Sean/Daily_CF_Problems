#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void res(int i) {
    string ans = "000000000";
    int cur = 0;
    while (i) {
        ans[8 - cur] = '0' + i % 10;
        i /= 10;
        ++cur;
    }
    cout << 1 << " " << ans << "\n";
}

void solve() {
    int a, b, mod;
    cin >> a >> b >> mod;
    if (b >= mod) {
        cout << 2 << "\n";
        return;
    }
    constexpr int base = 1e9;
    // b < mod ==> If exists a, s.t. mod - a * 1e9 % mod > b, then a wins, otherwise b wins
    int ub = min(a, mod);
    for (int i = 0; i <= ub; ++i) {
        int m = (1LL * i * base) % mod;
        if (m) m = mod - m;
        if (m > b) {
            res(i);
            return;
        }
    }
    cout << 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
