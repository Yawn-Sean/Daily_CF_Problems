#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int g(int x, int y) {
    if (x == 1 && y == 1) {
        return 0;
    }
    while (y > 0) {
        x = x / y;
        swap(x, y);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n + 1);
    for (int t = 2; t * t <= n; t++) {
        for (int y = t; y <= n / t; y++) {
            int f = g(y, t);
            if (y % f != 0) {
                continue;
            }
            int m = y / f;
            int l = t * m, r = min(t * m + m - 1, n / f);
            for (int a = l; a <= r; a++) {
                if (__gcd(a, m) == 1) {
                    p[a * f].push_back(y);
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        p[i].push_back(i);
    }

    vector<array<int, 2>> ans;
    for (int i = 1; i <= n; i++) {
        rgs::sort(p[i]);
        for (const auto& v : p[i]) {
            ans.push_back({i, v});
        }
    }

    int m = ans.size();
    while (q--) {
        i64 x;
        cin >> x;
        if (x <= m) {
            auto [l, r] = ans[x - 1];
            cout << l << " " << r << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }
    return 0;
}