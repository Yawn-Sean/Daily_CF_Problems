#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, q;
    cin >> n;
    vector<int> s(n), pre(n + 1);
    for (int &si : s) {
        cin >> si;
    }
    ranges::sort(s);
    for (int i = 0; i < n - 1; ++i) {
        s[i] = s[i + 1] - s[i];
    }
    s[n - 1] = INF;
    ranges::sort(s);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + s[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = ranges::lower_bound(s, r - l + 1) - s.begin();
        cout << pre[x] + (r - l + 1) * (n - x) << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
