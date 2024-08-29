#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> pre(2*n+1);
    for (int i = 0; i < 2 * n; ++i) {
        int u; cin >> u;
        [[assume(u == 1 || u == 2)]];
        pre[i+1] = pre[i] + (u * 2 - 3);
    }
    int sum = pre[2*n], ans = 2 * n;
    map<int, int> idx;
    for (int i = 0; i <= n; ++i) idx[pre[i]] = i;
    for (int i = n; i <= 2 * n; ++i) if (idx.count(pre[i] - sum))
        ans = min(ans, i - idx[pre[i] - sum]);
    println("{}", ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    // T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
