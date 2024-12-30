#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> vec; // 记录频次
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        vec[v]++;
        mp[vec[v]] += vec[v];

        int& c = mp[vec[v]]; // 出现 vec[v] 次的数个数 * vec[v]
        /*
            c == i      有一个数多出现了一次    最后结果加 1，表示总个数
            c == i + 1  均匀                   最后结果加 1，表示需要再多一个数
        <==>
            c >= i
        */
        if (c >= i && c < n) { // c < n 限制：原数组均匀出现（不合法情况）
            ans = c;
            // cout << format("c = {}, i = {}", c, i) << "\n";
        }
    }
    cout << ans + 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
