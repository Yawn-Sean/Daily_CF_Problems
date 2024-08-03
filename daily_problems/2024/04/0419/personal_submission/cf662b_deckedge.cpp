#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, char>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = red(), m = red(), vis[n];
    vector<vector<int>> part(3); 
    vector<vector<pi>> g(n);

    while (m--) {
        int u = red(), v = red();
        char c;
        cin >> c;
        --u, --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    function<bool(int, int, char)> Dfs = [&](int u, int p, char c) -> bool {
        if (vis[u]) {
            return vis[u] == p;
        }

        vis[u] = p;
        part[p].emplace_back(u);
        for (auto x : g[u]) {
            if (!Dfs(x.fi, x.se == c ? p : p ^ 3, c)) {
                return false;
            }
        }
        return true;
    };

    auto solve = [&](char c) {
        vector<int> res;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                part[1].clear();
                part[2].clear();

                if (!Dfs(i, 1, c)) {
                    for (int j = 0; j <= n; ++j) {
                        res.emplace_back(-1);
                    }
                    return res;
                }

                int f = 1;
                if (part[2].size() < part[1].size()) {
                    f = 2;
                }

                res.insert(res.end(), part[f].begin(), part[f].end());
            }
        }
        return res;
    };

    auto a = solve('B');
    auto b = solve('R');

    if (a.size() > b.size()) {
        a = b;
    }

    if (a.size() > n) {
        cout << -1;
    } else {
        cout << a.size() << '\n';
        for (int x : a) {
            cout << x + 1 << ' ';
        }
    }

    cout << '\n';
    return 0;
}

/*
对于一个点，最多对其操作一次，所以我们可以把点分为两类--操作一次的和不操作的

我们可以假设最终全是'R'

那么，对于一条红色的边，它的两个顶点要么都操作一次，要么都不操作，所以这两个点一定属于同一类，（同一个阵营），

对于一条蓝色的边，它的两个顶点其一必然需要操作一次，所以这两个点必然不属于一类。

注意原图可能不联通，所以我们可以对原图的所有连通块，判断其能否分成两部分（有点像二分染色），然后将点数小的部分加入答案。

*/