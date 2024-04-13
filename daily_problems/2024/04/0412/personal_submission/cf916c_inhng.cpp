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
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    m -= n - 1;
    cout << mod << " " << mod << endl;;
    for (int i = 1; i < n - 1; ++i) {
        cout << i << " " << i + 1 << " " << 1 << endl;
    }
    cout << n - 1 << " " << n << " " << mod - (n - 2) << endl;
    for (int i = 1; i <= n and m; ++i) {
        for (int j = i + 2; j <= n and m; ++j) {
            cout << i << " " << j << " " << (int)1e9 << endl;
            --m;
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
