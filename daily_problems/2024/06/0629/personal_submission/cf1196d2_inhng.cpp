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
    int n, k, ans = 200001;
    string s, ss = "RGB";
    cin >> n >> k >> s;
    for (int j = 0; j < 3; ++j) {
        int cnt = 0;
        vector<int> cur(n);
        for (int i = 0; i < n; ++i) {
            cur[i] = (s[i] != ss[(i + j) % 3]);
            cnt += cur[i];
            if (i >= k) {
                cnt -= cur[i - k];
            }
            if (i >= k - 1) {
                ans = min(ans, cnt);
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
