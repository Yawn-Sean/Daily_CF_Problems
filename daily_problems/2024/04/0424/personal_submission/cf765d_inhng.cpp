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
    vector<int> f(n), g(n), h;
    for (int &fi : f) {
        cin >> fi;
        --fi;
    }
    for (int i = 0; i < n; ++i) {
        if (f[f[i]] != f[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i] == i) {
            g[i] = h.size();
            h.emplace_back(f[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        g[i] = g[f[i]];
    }
    cout << h.size() << endl;
    for (int i = 0; i < n; ++i) {
        cout << g[i] + 1 << " \n"[i == n - 1];
    }
    for (int hi : h) {
        cout << hi + 1 << " \n"[hi == h.back()];
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
