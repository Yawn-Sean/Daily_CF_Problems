#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 10], B[MAXN + 10];

int flag[MAXN + 10], f[MAXN + 10], g[MAXN + 10], tree1[MAXN + 10], tree2[MAXN + 10];
int tree3[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int *tree, int pos, int val) {
    pos++;
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int *tree, int pos) {
    pos++;
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    for (int i = 1; i <= n; i++) {
        f[i] = A[i] - query(tree1, A[i]);
        g[i] = B[i] - query(tree2, B[i]);
        if (f[i] + g[i] >= n + 1 - i) flag[i] = 1;
        else if (f[i] + g[i] + 1 < n + 1 - i) flag[i] = 0;
        else flag[i] = -1;
        add(tree1, A[i], 1);
        add(tree2, B[i], 1);
    }

    for (int i = n, last = 0; i > 0; i--) {
        if (flag[i] == -1) flag[i] = last;
        else last = flag[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = (f[i] + g[i] + flag[i + 1]) % (n + 1 - i);
        int head = 0, tail = n - 1;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (mid - query(tree3, mid) >= x) tail = mid;
            else head = mid + 1;
        }
        printf("%d%c", head, "\n "[i < n]);
        add(tree3, head, 1);
    }

    return 0;
}
