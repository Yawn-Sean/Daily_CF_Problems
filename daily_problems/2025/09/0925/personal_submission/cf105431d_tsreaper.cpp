#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
#define MAXK 15
using namespace std;

int n, K, ans, A[MAXN * MAXK + 5];
vector<int> pos[MAXN + 5];

int tree[MAXN * MAXK + 5];

int lb(int x) { return x & (-x); }

void modify(int pos, int val) {
    for (; pos <= n * K; pos += lb(pos)) tree[pos] = max(tree[pos], val);
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret = max(ret, tree[pos]);
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n * K; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n * K; i++) {
        int x; scanf("%d", &x);
        pos[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) reverse(pos[i].begin(), pos[i].end());
    for (int i = 1; i <= n * K; i++) for (int x : pos[A[i]]) {
        int val = query(x - 1) + 1;
        ans = max(ans, val);
        modify(x, val);
    }
    printf("%d\n", ans);
    return 0;
}
