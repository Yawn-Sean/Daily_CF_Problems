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
    int n, k, cnt = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i) {
        pre[i] = a[i] + pre[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        while (i < n and a[i + 1] == a[i]) {
            ++i;
        }
        int left = -1, right = i;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            (a[i] * (i - mid) - (pre[i] - pre[mid]) > k ? left : right) = mid;
        }
        if (i - left > cnt) {
            cnt = i - left;
            ans = a[i];
        }
    }
    cout << cnt - 1 << " " << ans << endl;
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
