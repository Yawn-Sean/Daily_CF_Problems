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
    cin >> n;
    vector<int> p(n), mx(2, -1), mid(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (mx[0] == -1 or p[i] > p[mx[0]]) {
            mid[i]--;
            mx[1] = mx[0];
            mx[0] = i;
        } else if (mx[1] == -1 or p[i] > p[mx[1]]) {
            mid[mx[0]]++;
            mx[1] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mid[i] > mid[ans] or (mid[i] == mid[ans] and p[i] < p[ans])) {
            ans = i;
        }
    }
    cout << p[ans] << endl;
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
