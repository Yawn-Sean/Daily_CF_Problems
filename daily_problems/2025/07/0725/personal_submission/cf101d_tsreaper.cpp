#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<long long, int> pli;

int n;

vector<int> e[MAXN + 5], v[MAXN + 5];
int sz[MAXN + 5];
long long f[MAXN + 5], g[MAXN + 5];

void dfs(int sn, int fa) {
    vector<pli> vec;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        dfs(fn, sn);
        sz[sn] += sz[fn];
        f[sn] += f[fn] + 1LL * v[sn][i] * sz[fn];
        long long t = g[fn] + v[sn][i] * 2;
        g[sn] += t;
        vec.push_back({t, sz[fn]});
    }

    sort(vec.begin(), vec.end(), [&](pli &a, pli &b) {
        return b.first * a.second - a.first * b.second > 0;
    });
    long long rem = sz[sn];
    for (pli p : vec) {
        rem -= p.second;
        f[sn] += p.first * rem;
    }

    sz[sn]++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    dfs(1, 0);
    printf("%.12f\n", 1.0 * f[1] / (n - 1));
    return 0;
}
