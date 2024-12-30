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
    int n = red(), st, ed;
    vector<vector<int>> a(n + 1);
    rep(i, 0, n) {
        int u = red(), v = red();
        u--, v--;
        if (!i) {
            st = u;
            ed = v;
        }
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    if (a[0][0] != st && a[0][0] != ed) {
        swap(a[0][0], a[0][1]);
    }
    int cnt = 0;
    function<void(int, int)> Dfs = [&](int u, int p) -> void {
        cnt++;
        if (cnt > n) {
            return ;
        }
        cout << u + 1 << ' ';
        rep(i, 0, a[u].size()) {
            int v = a[u][i];
            if (v != p) {
                Dfs(v, u);
            }
        }
    };
    Dfs(0, -1);
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

/*
https://codeforces.com/problemset/problem/1095/D
*/