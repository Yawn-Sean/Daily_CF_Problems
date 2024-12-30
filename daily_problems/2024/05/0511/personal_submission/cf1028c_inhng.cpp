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
    int n;
    cin >> n;
    int x[2] = {-INF, INF}, y[2] = {-INF, INF};
    vector<array<int, 4>> rect(n);
    for (int i = 0; i < n; ++i) {
        cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
        x[0] = max(x[0], rect[i][0]);
        y[0] = max(y[0], rect[i][1]);
        x[1] = min(x[1], rect[i][2]);
        y[1] = min(y[1], rect[i][3]);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                if (x[i] >= rect[k][0] and x[i] <= rect[k][2] and y[j] >= rect[k][1] and y[j] <= rect[k][3]) {
                    cnt++;
                }
            }
            if (cnt >= n - 1) {
                cout << x[i] << " " << y[j] << endl;
                return;
            }
        }
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
