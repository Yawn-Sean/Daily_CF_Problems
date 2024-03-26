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
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n + 1), idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] ^ i) {
            a[idx[i]] = a[i];
            idx[a[i]] = idx[i];
            ++cnt;
        }
    }
    cout << ((cnt + 3 * n) & 1 ? "Um_nik" : "Petr") << endl;
}
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
