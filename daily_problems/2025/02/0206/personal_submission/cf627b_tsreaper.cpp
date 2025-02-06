#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, q;
long long X, Y, A[MAXN + 5];

long long tree[2][MAXN + 5];

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
    scanf("%d%d%lld%lld%d", &n, &K, &X, &Y, &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x, y; scanf("%d%d", &x, &y);
            add(tree[0], x, -min(A[x], Y));
            add(tree[1], n + 1 - x, -min(A[x], X));
            A[x] += y;
            add(tree[0], x, min(A[x], Y));
            add(tree[1], n + 1 - x, min(A[x], X));
        } else {
            int d; scanf("%d", &d);
            long long x = query(tree[0], d - 1), y = 0;
            if (d + K - 1 <= n) y = query(tree[1], n + 1 - (d + K));
            printf("%lld\n", x + y);
        }
    }
    return 0;
}
