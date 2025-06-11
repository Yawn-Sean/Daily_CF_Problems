#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define erp(i, a, b) for (int i = a; i >= b; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

const int mod = 1000000007, mod0 = 998244353;

void solve() {
    const int s = 1e6;
    int n;
    cin >> n;
    vector<bool> vis(s + 1, false);
    vector<int> x(n + 1);
    rep (i, 1, n) {
        cin >> x[i];
        vis[x[i]] = true;
    }
    vector<int> y;
    int cnt = n;
    rep (i, 1, n) {
        int w = s + 1 - x[i];
        if (vis[w])
            continue;
        vis[w] = true;
        y.push_back(w);
        --cnt;
    }
    int i = 1;
    while (cnt) {
        if (!vis[i]) {
            int w = s + 1 - i;
            vis[w] = vis[i] = true;
            y.push_back(i);
            y.push_back(w);
            cnt -= 2;
        }
        ++i;
    }
    cout << int(y.size()) << endl;
    for (int &v : y)
        cout << v << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
