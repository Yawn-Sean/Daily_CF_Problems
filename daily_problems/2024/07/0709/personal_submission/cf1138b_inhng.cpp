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
    int n, all = 0;
    cin >> n;
    string a, c;
    cin >> c >> a;
    vector<int> cnt[3];
    for (int i = 0; i < n; ++i) {
        all += c[i] == '1';
        cnt[c[i] - '0' + a[i] - '0'].emplace_back(i + 1);
    }
    for (int i2 = 0; i2 <= cnt[2].size(); ++i2) {
        int i1 = all - i2 * 2, i0 = n / 2 - i1 - i2;
        if (i1 >= 0 and i1 <= cnt[1].size() and i0 >= 0 and i0 <= cnt[0].size()) {
            for (int i = i0; i < cnt[0].size(); ++i) {
                cout << cnt[0][i] << " ";
            }
            for (int i = i1; i < cnt[1].size(); ++i) {
                cout << cnt[1][i] << " ";
            }
            for (int i = i2; i < cnt[2].size(); ++i) {
                cout << cnt[2][i] << " ";
            }
            return;
        }
    }
    cout << -1 << endl;
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
