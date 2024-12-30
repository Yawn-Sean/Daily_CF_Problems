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
    int cnt[4];
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    string s = "ABCD";
    vector<string> g(50, string(50, ' '));
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            g[i][j] = s[i / 25 * 2 + j / 25];
        }
    }
    for (int idx = 0; idx < 4; ++idx) {
        int x = (idx + 1) % 4 / 2, y = (idx + 1) % 4 % 2;
        for (int i = 1; i < 25; i += 2) {
            for (int j = 1; j < 25; j += 2) {
                if (cnt[idx] > 1) {
                    cnt[idx]--;
                    g[i + x * 25][j + y * 25] = s[idx];
                }
            }
        }
    }
    cout << "50 50" << endl;
    for (string gi : g) {
        cout << gi << endl;
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
