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
    vector<int> a(n + 1), b(n + 1), ans, up, down;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] < b[i]) {
            up.emplace_back(i);
        } else {
            down.emplace_back(i);
        }
    }
    if (up.size() > down.size()) {
        ranges::sort(up, [&](int i, int j) {
            return b[i] > b[j];
        });
        ans = up;
    } else {
        ranges::sort(down, [&](int i, int j) {
            return a[i] < a[j];
        });
        ans = down;
    }
    cout << ans.size() << endl;
    for (int ai : ans) {
        cout << ai << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
