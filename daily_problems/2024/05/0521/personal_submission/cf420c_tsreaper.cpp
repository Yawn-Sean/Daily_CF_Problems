#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, K, A[MAXN + 10];
long long ans;

vector<int> e[MAXN + 10];
int tree[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    pos++;
    for (; pos <= n + 1; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    pos++;
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        A[x]++; A[y]++;
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) add(A[i], 1);

    for (int x = 1; x <= n; x++) {
        int base = e[x].size();
        for (int y : e[x]) add(A[y], -1), add(--A[y], 1);
        ans += query(n) - query(max(0, K - base) - 1);
        if (base * 2 >= K) ans--;
        for (int y : e[x]) add(A[y], -1), add(++A[y], 1);
    }
    printf("%lld\n", ans / 2);
    return 0;
}
