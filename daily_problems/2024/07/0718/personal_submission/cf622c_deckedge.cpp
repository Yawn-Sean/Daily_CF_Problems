#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    ve<int> a(n), pre(n);
    rep(i, 0, n) {
        cin >> a[i];
        if (!i || a[i] != a[i - 1]) {
            pre[i] = i - 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    while (m--) {
        int l, r, val;
        cin >> l >> r >> val;
        l--, r--;
        if (a[r] != val) {
            cout << r + 1 << '\n';
        } else if (pre[r] >= l) {
            cout << pre[r] + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
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



