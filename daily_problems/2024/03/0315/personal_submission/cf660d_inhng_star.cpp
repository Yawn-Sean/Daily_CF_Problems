#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<PII> point(n);
    for (auto &[x, y] : point) {
        cin >> x >> y;
    }
    sort(point.begin(), point.end()); // 方便计算 \delta x 和 \delta y
    map<PII, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x = point[j].ff - point[i].ff, y = point[j].ss - point[i].ss;
            ans += mp[{x, y}]++; // 平行四边形的两条边平行
        }
    }
    cout << ans / 2 << endl; // 一个四边形有两个对边，也就是一个四边形会被重复判断两次
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
