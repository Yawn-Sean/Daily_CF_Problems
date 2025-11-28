#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q, A[MAXN + 5];
int tree[MAXN * 4 + 5], fac[MAXN + 5];

void modify(int id, int l, int r, int qpos, int qv) {
    if (l == r) tree[id] = qv;
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (qpos <= mid) modify(nxt, l, mid, qpos, qv);
        else modify(nxt | 1, mid + 1, r, qpos, qv);
        tree[id] = gcd(tree[nxt], tree[nxt | 1]);
    }
}

void print() {
    if (tree[1] == 0) printf("%d\n", n);
    else printf("%d\n", fac[tree[1]]);
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    memset(tree, 0, sizeof(int) * (n * 4 + 3));
    for (int i = 1; i < n; i++) if (A[i] > A[i + 1]) modify(1, 1, n, i, i);
    print();

    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        A[x] = y;
        if (x > 1) {
            if (A[x - 1] > A[x]) modify(1, 1, n, x - 1, x - 1);
            else modify(1, 1, n, x - 1, 0);
        }
        if (x < n) {
            if (A[x] > A[x + 1]) modify(1, 1, n, x, x);
            else modify(1, 1, n, x, 0);
        }
        print();
    }
}

int main() {
    for (int i = 1; i <= MAXN; i++) for (int j = i; j <= MAXN; j += i) fac[j]++;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
