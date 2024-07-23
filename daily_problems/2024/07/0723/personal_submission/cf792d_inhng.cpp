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
    int n, q;
    cin >> n >> q;
    while (q--) {
        int u;
        string s;
        cin >> u >> s;
        for (char c : s) {
            int x = u & -u;
            if (c == 'L') {
                if (x > 1) {
                    u -= x / 2;
                }
            } else if (c == 'R') {
                if (x > 1) {
                    u += x / 2;
                }
            } else if (x * 2 < n) {
                u -= x;
                u |= x * 2;
            }
        }
        cout << u << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
