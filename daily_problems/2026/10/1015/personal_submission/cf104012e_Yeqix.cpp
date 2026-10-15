#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> f(n);
    for (auto& x : f) {
        cin >> x;
    }

    i64 ans = 1;
    auto get = [&](string s) -> i64 {
        s = '.' + s + '.';
        i64 res = 1;
        i64 cnt = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (s[i] == '?') {
                cnt++;
            } else {
                if (cnt) {
                    int v = (s[i] == '#') + (s[i - cnt - 1] == '#');
                    if (v == 2) {
                        return 0;
                    } else if (v == 0) {
                        res = res * (cnt + 1) % md;
                    }
                    cnt = 0;
                }
            }
        }

        return res;
    };

    for (const auto& x : f) {
        ans = ans * get(x) % md;
    }
    for (int j = 0; j < n; j++) {
        string t;
        for (int i = 0; i < n; i++) {
            t += f[i][j];
        }

        ans = ans * get(t) % md;
    }

    cout << ans;
    return 0;
}