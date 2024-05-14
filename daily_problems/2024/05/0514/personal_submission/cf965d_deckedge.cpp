#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), l = red(), res = 2e9;
    vector<int> a(n - 1), pre(n);
    generate(all(a), red);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] + a[i];
    }
    rep(i, l, n) {
        res = min(res, pre[i] - pre[i - l]);
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

