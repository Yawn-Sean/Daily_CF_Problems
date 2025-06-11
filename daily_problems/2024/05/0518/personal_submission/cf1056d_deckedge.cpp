#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define eb emplace_back
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
    int n = red();
    vector<int> sz(n + 1), cnt(n + 1);
    vector<vector<int>> e(n + 1);
    rep(i, 2, n + 1) {
        int x = red();
        e[x].eb(i);
    } 
    function<void(int)> Dfs = [&](int u) {
        bool flag = true;
        for (auto v : e[u]) {
            flag = false;
            Dfs(v);
            sz[u] += sz[v];
        }
        sz[u] += flag;
        cnt[sz[u]]++;
    };
    Dfs(1);
    rep (i, 1, n + 1) {
        rep(j, 0, cnt[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
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
