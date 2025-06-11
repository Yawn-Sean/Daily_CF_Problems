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
    int n, k, mx = 0;
    cin >> n >> k;
    vector<PII> a[200010];
    set<PII> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[l].emplace_back(r, i);
        mx = max(mx, r);
    }

    for (int i = 1; i <= mx; ++i) {
        for (PII aij : a[i]) {
            s.insert(aij);
        }
        while (s.size() and s.size() > k) {
            ans.emplace_back(s.rbegin()->ss + 1);
            s.erase(*s.rbegin());
        }
        while (s.size() and s.begin()->ff == i) {
            s.erase(*s.begin());
        }
    }
    cout << ans.size() << endl;
    for (int ai : ans) {
        cout << ai << " \n"[ai == ans.back()];
    }
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
