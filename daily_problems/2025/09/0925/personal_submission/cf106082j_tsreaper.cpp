#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
long long ans[MAXN + 5][MAXN + 5];

struct Edge {
    long long len;
    int sn, fn;
} e[MAXN * (MAXN - 1) / 2 + 5];
int root[MAXN + 5];
vector<int> vec[MAXN + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    int m = 0;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        long long d = 1LL * (X[i] - X[j]) * (X[i] - X[j]) + 1LL * (Y[i] - Y[j]) * (Y[i] - Y[j]);
        e[++m] = {d, i, j};
    }
    sort(e + 1, e + m + 1, [&](auto &a, auto &b) {
        return a.len < b.len;
    });

    for (int i = 1; i <= n; i++) root[i] = i, vec[i].push_back(i);
    for (int i = 1, rem = n; i <= m && rem > 1; i++) {
        int x = findroot(e[i].sn), y = findroot(e[i].fn);
        if (x == y) continue;
        rem--;
        if (vec[x].size() > vec[y].size()) swap(x, y);
        for (int a : vec[x]) for (int b : vec[y]) ans[a][b] = ans[b][a] = e[i].len;
        root[x] = y;
        for (int a : vec[x]) vec[y].push_back(a);
    }

    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%.12f\n", sqrt(ans[x][y]));
    }
    return 0;
}
