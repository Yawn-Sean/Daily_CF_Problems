#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, K;
long long ans;

int tree[MAXN + 5];

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
    scanf("%d%d", &n, &K);
    if (K > n / 2) K = n - K;
    ans = 1;
    for (int i = 1, j = 1; i <= n; i++) {
        int jj = j + K;
        if (jj > n) {
            ans += query(jj - n - 1) + query(n) - query(j) + 1;
            add(j, 1); add(jj - n, 1);
            j = jj - n;
        } else {
            ans += query(jj - 1) - query(j) + 1;
            add(j, 1); add(jj, 1);
            j = jj;
        }
        printf("%lld%c", ans, "\n "[i < n]);
    }
    return 0;
}
