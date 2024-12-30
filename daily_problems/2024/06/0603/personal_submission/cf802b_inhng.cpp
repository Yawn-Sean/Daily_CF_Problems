#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n), idx(n + 1, n + 1), nxt(n);
    set<PII> s;
    for (int &ai : a) {
        cin >> ai;
    }
    for (int i = n - 1; ~i; --i) {
        nxt[i] = idx[a[i]]; // 该元素下一个位置在哪
        idx[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (s.count({-i, a[i]})) { // 借出
            s.erase({-i, a[i]});
        } else {
            ++ans;
        }
        if (s.size() == k) {
            s.erase(s.begin());
        }
        s.insert({-nxt[i], a[i]}); // 距离此位置远的先删除
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
