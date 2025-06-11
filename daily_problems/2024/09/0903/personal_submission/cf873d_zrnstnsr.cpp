#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> f;
    auto cal = [&](this auto &&self, int x) -> int {
        if (!f.count(x)) f[x] = 1 + self(x / 2) + self(x - x / 2);
        return f[x];
    };
    f[1] = 1;
    cal(n);
    if (k % 2 == 0 || k > f[n]) { println("-1"); return; }
    int l = 0, r = n;
    vector<int> ans(n);
    iota(ans.rbegin(), ans.rend(), 1);
    while (--k) {
        int m = l + (r - l) / 2;
        if (f[m-l] <= k) {
            k -= f[m-l];
            l = m;
        } else {
            reverse(ans.begin() + m, ans.begin() + r);
            r = m;
            --k;
        }
    }
    reverse(ans.begin() + l, ans.begin() + r);
    for (auto v: ans) print("{} ", v);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
