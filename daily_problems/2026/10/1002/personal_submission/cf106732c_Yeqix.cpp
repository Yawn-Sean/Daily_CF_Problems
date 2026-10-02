#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using ld = long double;
namespace rgs = std::ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m;
    cin >> n >> m;
    vector<array<i64, 2>> a;
    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        i64 x;
        cin >> x;
        if (c == 'S') {
            a.push_back({x, 0});
        } else {
            a.push_back({x, 1});
        }
    }

    rgs::sort(a, greater<array<i64, 2>>());

    cout << fixed << setprecision(12);
    ld ans = 0;
    i64 cnt = 0;
    for (const auto& [l, r] : a) {
        if (r) {
            if (ans * cnt + 1 <= l * (cnt + 1)) {
                ans = l;
            } else {
                ans = (ans * cnt + 1) / (cnt + 1);
            }
        } else {
            ans = (ans * cnt + l) / (cnt + 1);
        }
        cnt++;
    }

    cout << ans << " ";

    rgs::reverse(a);
    ans = 0, cnt = 0;
    for (const auto& [l, r] : a) {
        if (r) {
            if (ans * cnt + n >= l * (cnt + 1)) {
                ans = l;
            } else {
                ans = (ans * cnt + n) / (cnt + 1);
            }
        } else {
            ans = (ans * cnt + l) / (cnt + 1);
        }
        cnt++;
    }

    cout << ans;
    return 0;
}