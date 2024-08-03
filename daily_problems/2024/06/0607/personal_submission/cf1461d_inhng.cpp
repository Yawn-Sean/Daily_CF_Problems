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
    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    ranges::sort(a);
    partial_sum(a.begin(), a.end(), pre.begin());
    
    function<void(int, int)> dfs = [&](int left, int right) {
        if (left > right) {
            return;
        }
        s.insert(pre[right] - pre[left - 1]);
        if (a[left] == a[right]) {
            return;
        }
        int mid = (a[left] + a[right]) >> 1;
        mid = ranges::upper_bound(a, mid) - a.begin() - 1;
        dfs(left, mid);
        dfs(mid + 1, right);
    };
    
    dfs(1, n);
    while (q--) {
        int target;
        cin >> target;
        cout << (s.count(target) ? "Yes" : "No") << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    int Test; cin >> Test; while (Test--)
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
