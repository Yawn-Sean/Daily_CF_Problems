#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m, mid = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &ai : a) {
        cin >> ai;
        mid ^= ai;
    }
    for (int &bi : b) {
        cin >> bi;
        mid ^= bi;
    }
    if (mid) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ans(m, a[0]);
    for (int i = 1; i < m; ++i) {
        ans[i] = b[i];
        ans[0] ^= b[i];
    }
    for (int ai : ans) {
        cout << ai << " ";
    }
    cout << endl;
    for (int i = 1; i < n; ++i) {
        cout << a[i] << " ";
        for (int j = 1; j < m; ++j) {
            cout << "0 ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
