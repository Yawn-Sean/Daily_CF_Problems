#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m, ans = INF;
    cin >> n >> m;
    vector<int> a[m + 1];
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        a[p].emplace_back(c); // 每个政党手下的投票需要多少钱贿赂
    }
    for (int i = 1; i <= m; ++i) { // 每个政党需要贿赂的钱从小到大排序
        ranges::sort(a[i]);
    }
    for (int i = max((int)a[1].size(), 1ll); i <= n; ++i) { // 枚举 1 政党获胜需要的票数
        int mid = 0, cnt = 0;
        vector<int> all;
        for (int j = 2; j <= m; ++j) {
            int k = 0;
            for (; k + i <= a[j].size(); ++k) { // 其他政党的票数需要小于 i
                mid += a[j][k];
                ++cnt;
            }
            for (; k < a[j].size(); ++k) { // 没贿赂的票先存起来
                all.emplace_back(a[j][k]);
            }
        }
        ranges::sort(all);
        for (int j = 0; j < all.size() and a[1].size() + cnt < i; ++j) {
            mid += all[j]; // 如果还不够 1 赢，就继续贿赂
            ++cnt;
        }
        ans = min(ans, mid);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
