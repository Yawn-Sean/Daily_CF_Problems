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
    int n, mx_frequent = 0, ans = 0;
    cin >> n;
    unordered_map<int, int> cnt, cnt_frequent;
    cnt_frequent[0] = n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt_frequent[cnt[x]]--;
        cnt[x]++;
        cnt_frequent[cnt[x]]++;
        mx_frequent = max(mx_frequent, cnt[x]);
        if (mx_frequent == 1 or 
            mx_frequent * cnt_frequent[mx_frequent] == i - 1 or 
            (mx_frequent - 1) * (cnt_frequent[mx_frequent - 1] + 1) == i - 1) {
            ans = i;
        }
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
