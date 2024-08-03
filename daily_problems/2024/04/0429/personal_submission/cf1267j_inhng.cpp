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
    int n, mn = INF, ans = INF;
    cin >> n;
    vector<int> cnt(n + 1), a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (not cnt[i]) {
            continue;
        }
        a.emplace_back(cnt[i]);
        mn = min(mn, cnt[i]);
    }

    function<int(int)> f = [&](int x) -> int {
        int cnt = 0;
        for (int ai : a) {
            int num = ai / x, more = ai % x;
            if (more) {
                more = x - 1 - more;
                if (num < more) {
                    return INF;
                }
                ++num;
            }
            cnt += num;
        }
        return cnt;
    };

    for (int i = mn + 1; i; --i) {
        ans = min(ans, f(i));
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
