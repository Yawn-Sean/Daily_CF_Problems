#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, T;
    cin >> n >> T;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> t[i];
    int L = 0, R = n + 1;
    vector<int> ans;
    auto check = [&](int m, bool out = false) -> bool {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) if (a[i] >= m) {
            q.push({t[i], i});
            if (q.size() > m) q.pop();
        }
        int sum = 0;
        if (q.size() < m) return false;
        if (out) ans.reserve(q.size());
        while (!q.empty()) {
            sum += q.top().first;
            if (out) ans.push_back(q.top().second + 1);
            q.pop();
        }
        if (out) {
            println("{}\n{}", ans.size(), ans.size());
            for (auto v: ans) print("{} ", v);
            println();
        }
        return sum <= T;
    };
    while (L < R) {
        int m = L + (R - L) / 2;
        if (check(m)) L = m + 1;
        else R = m;
    }
    check(L - 1, true);
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
