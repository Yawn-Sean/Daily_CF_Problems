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
    int ans = 0;
    string s;
    cin >> s;
    vector<int> pre(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            pre[i + 1] = pre[i] + 1;
        }
    }
    for (int r = 0; r < s.size(); ++r) {
        int mid = 0;
        for (int l = r; ~l and r - l < 19; --l) {
            if (s[l] == '0') {
                continue;
            }
            mid |= 1 << (r - l);
            if (mid <= r - l + 1 + pre[l]) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
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
