#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[MAXN + 5], pos[MAXN + 5], tree[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        pos[A[i]] = i;
    }
    for (int i = 1; i <= n; i++) if (pos[i + 1] < pos[i]) add(i, 1);

    int q; scanf("%d", &q);
    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            printf("%d\n", query(y - 1) - query(x - 1) + 1);
        } else {
            vector<int> vec = {A[x] - 1, A[x], A[y] - 1, A[y]};
            sort(vec.begin(), vec.end());
            vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
            for (int t : vec) if (t > 0) {
                int v = query(t) - query(t - 1);
                if (v) add(t, -1);
            }
            swap(pos[A[x]], pos[A[y]]);
            swap(A[x], A[y]);
            for (int t : vec) if (t > 0 && pos[t + 1] < pos[t]) add(t, 1);
        }
    }
    return 0;
}
