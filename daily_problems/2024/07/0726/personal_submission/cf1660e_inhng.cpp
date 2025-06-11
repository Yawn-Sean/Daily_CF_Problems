#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, cnt1 = 0, ans = INF;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0, k = (n - i) % n; j < n; ++j, k = (k + 1) % n) {
            if (s[j] == '1') {
                ++cnt1;
                cnt[k]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans = min(ans, n + cnt1 - 2 * cnt[i]);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
