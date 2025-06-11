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
    int n, ans = 0;
    string s, t, ans_t;
    cin >> s >> t >> n;
    if (s.size() != t.size()) {
        cout << -1 << endl;
        return;
    }

    vector g(26, vector<int>(26, INF)), dist(26, vector<int>(26, INF)), ok(26, vector<int>(26, -1));
    for (int i = 0; i < 26; ++i) {
        g[i][i] = 0;
    }
    while (n--) {
        char u ,v;
        int d;
        cin >> u >> v >> d;
        g[u - 'a'][v - 'a'] = min(g[u - 'a'][v - 'a'], d);
    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                if (g[i][k] + g[j][k] < dist[i][j]) {
                    dist[i][j] = g[i][k] + g[j][k];
                    ok[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (ok[s[i] - 'a'][t[i] - 'a'] == -1) {
            cout << -1 << endl;
            return;
        }
        ans += dist[s[i] - 'a'][t[i] - 'a'];
        ans_t += 'a' + ok[s[i] - 'a'][t[i] - 'a'];
    }
    cout << ans << endl << ans_t;
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
