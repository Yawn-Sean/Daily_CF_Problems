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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        int g = 0;
        for (int j = i; j < n; ++j) {
            g = gcd(g, a[j]);
            // cout << a[i] << " " << a[j] << " " << gcd(a[i], a[j]) << endl;
            if (g == 1) {
                ans = min(ans, j - i);
                break;
            }
        }
    }
    if (ans > n) {
        cout << -1;
        return;
    }
    int cnt = ranges::count(a, 1);
    if (cnt) {
        ans = n - cnt;
    } else {
        ans += n - 1;
    }
    cout << ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
