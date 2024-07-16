#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXK 10
using namespace std;

int n, K;
long long ans;

long long f[MAXN + 10][MAXK + 5], tree[MAXK + 5][MAXN + 10];

int lb(int x) { return x & (-x); }

void add(long long *tree, int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

long long query(long long *tree, int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        f[i][1] = 1;
        for (int j = 1; j <= K; j++) f[i][j + 1] = query(tree[j], x);
        for (int j = 1; j <= K + 1; j++) add(tree[j], x, f[i][j]);
    }
    for (int i = 1; i <= n; i++) ans += f[i][K + 1];
    printf("%lld\n", ans);
    return 0;
}
