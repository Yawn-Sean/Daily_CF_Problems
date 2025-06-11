#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

#define dbg(x) cerr << #x << " is " << x << "\n"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r[i].push_back(a[i][j]);
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            c[j].push_back(a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        ranges::sort(r[i]);
        r[i].erase(ranges::unique(r[i]).begin(), r[i].end());
    }
    for (int i = 0; i < m; i++) {
        ranges::sort(c[i]);
        c[i].erase(ranges::unique(c[i]).begin(), c[i].end());
    }

    vector ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ri = ranges::lower_bound(r[i], a[i][j]) - r[i].begin() + 1;
            int cj = ranges::lower_bound(c[j], a[i][j]) - c[j].begin() + 1;
            ans[i][j] = max(ri, cj) + max(r[i].size() - ri, c[j].size() - cj);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }

    return 0;
}
