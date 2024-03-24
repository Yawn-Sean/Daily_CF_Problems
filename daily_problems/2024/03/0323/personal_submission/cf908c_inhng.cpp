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
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    for (int &xi : x) {
        cin >> xi;
    }
    vector<double> y(n, r);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(x[i] - x[j]) <= 2 * r) {
                y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
            }
        }
        cout << y[i] << " ";
    }
}
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
