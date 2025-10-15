#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, ans, A[MAXN + 5];

int tree[3][MAXN + 5];

int lb(int x) { return x & (-x); }

void modify(int *tree, int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] = max(tree[pos], val);
}

int query(int *tree, int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret = max(ret, tree[pos]);
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        A[l]++; A[r + 1]--;
    }
    for (int i = 1; i <= m; i++) A[i] += A[i - 1];
    for (int i = 1; i <= m; i++) A[i]++;

    for (int i = 1; i <= m; i++) {
        int f[2] = {1, 1};
        f[0] = max(f[0], query(tree[0], A[i]) + 1);
        f[1] = max(f[1], query(tree[1], n + 1 - A[i]) + 1);
        f[1] = max(f[1], query(tree[2], n + 1 - A[i]) + 1);
        modify(tree[0], A[i], f[0]);
        modify(tree[1], n + 1 - A[i], f[0]);
        modify(tree[2], n + 1 - A[i], f[1]);
        ans = max({ans, f[0], f[1]});
    }
    printf("%d\n", ans);
    return 0;
}
