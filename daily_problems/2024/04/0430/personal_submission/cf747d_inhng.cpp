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
    int n, k, last = 0, cnt = 0;
    cin >> n >> k;
    vector<int> a(n + 1), summer;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] >= 0) {
            continue;
        }
        ++cnt;
        if (last) {
            summer.push_back(i - last - 1);
        }
        last = i;
    }
    if (cnt > k) {
        cout << -1 << endl;
        return;
    }
    ranges::sort(summer);
    int ans = cnt * 2;
    k -= cnt;
    for (int i = 0; i < summer.size() and k - summer[i] >= 0; ++i) {
        ans -= 2;
        k -= summer[i];
    }
    ans -= (last and k >= n - last);
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
