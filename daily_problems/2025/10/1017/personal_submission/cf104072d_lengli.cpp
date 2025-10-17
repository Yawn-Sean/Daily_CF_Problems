#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int i, int v = 1) {
        for (i++; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int sum(int l, int r) const {
        return sum(r) - sum(l);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &x : grid)
        for (auto &y : x)
            cin >> y;

    vector<vector<int>> u = grid, d = grid, l = grid, r = grid;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (u[i][j]) u[i][j] = u[i - 1][j] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (d[i][j]) d[i][j] = d[i + 1][j] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (l[i][j]) l[i][j] = l[i][j - 1] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (r[i][j]) r[i][j + 1];
            if (r[i][j]) r[i][j] = r[i][j + 1] + 1;
        }
    }

    auto solve = [&](int x, int y) -> long long {
        vector<int> v1, v2;

        while (x < n && y < n) { 
            v1.emplace_back(min(d[x][y], r[x][y]) - 1);
            v2.emplace_back(min(u[x][y], l[x][y]) - 1);
            x++, y++;
        }

        int k = (int)v1.size();
        long long ans = 0;

        Fenwick fen(k + 2);
        vector<vector<int>> tmp(k + 2);

        for (int i = 0; i < k; i++) {
            tmp[i - v2[i]].emplace_back(i);
        }

        for (int i = 0; i < k; i++) {
            for (auto &j : tmp[i]) fen.add(j, 1);
            ans += fen.sum(i + v1[i] + 1);
        }

        return ans - 1LL * k * (k - 1) / 2;
    };

    long long res = solve(0, 0);
    for (int i = 1; i < n; i++)
        res += solve(0, i) + solve(i, 0);

    cout << res << "\n";
    return 0;
}
