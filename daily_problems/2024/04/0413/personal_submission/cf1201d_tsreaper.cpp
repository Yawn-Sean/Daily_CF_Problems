#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

long long f[MAXN + 10][4];
int g[MAXN + 10][4];

long long calc(int from, int to, int L, int R) {
    if (from > to) swap(from, to);
    if (from < 0) return INF;
    return to - from + max(from - L, 0) * 2 + max(R - to, 0) * 2;
}

int main() {
    int n, K, q; scanf("%d%*d%d%d", &n, &K, &q);

    map<int, vector<int>> mp;
    while (K--) {
        int r, c; scanf("%d%d", &r, &c);
        mp[r].push_back(c);
    }
    mp[1].push_back(1);
    
    vector<int> good;
    while (q--) {
        int x; scanf("%d", &x);
        good.push_back(x);
    }
    sort(good.begin(), good.end());

    vector<array<int, 3>> vec;
    for (auto &p : mp) {
        sort(p.second.begin(), p.second.end());
        vec.push_back({p.first, p.second[0], p.second.back()});
    }
    n = vec.size();

    for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) {
        auto it = upper_bound(good.begin(), good.end(), vec[i][j + 1]);
        if (it == good.begin()) g[i][j * 2] = -1;
        else g[i][j * 2] = *prev(it);
        it = lower_bound(good.begin(), good.end(), vec[i][j + 1]);
        if (it == good.end()) g[i][j * 2 + 1] = -1;
        else g[i][j * 2 + 1] = *it;
    }

    if (n == 1) { printf("%d\n", vec[0][2] - 1); return 0; }
    for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) f[i][j] = INF;
    for (int j = 0; j < 4; j++) f[0][j] = calc(1, g[0][j], vec[0][1], vec[0][2]);
    for (int i = 1; i + 1 < n; i++) for (int j = 0; j < 4; j++) for (int jj = 0; jj < 4; jj++)
        f[i][j] = min(f[i][j], f[i - 1][jj] + calc(g[i - 1][jj], g[i][j], vec[i][1], vec[i][2]) + vec[i][0] - vec[i - 1][0]);

    long long ans = INF;
    for (int j = 0; j < 4; j++) {
        long long t = f[n - 2][j] + vec[n - 1][0] - vec[n - 2][0];
        t += min(
            calc(g[n - 2][j], vec[n - 1][1], vec[n - 1][1], vec[n - 1][2]),
            calc(g[n - 2][j], vec[n - 1][2], vec[n - 1][1], vec[n - 1][2]));
        ans = min(ans, t);
    }
    printf("%lld\n", ans);
    return 0;
}
