#include <bits/stdc++.h>
#define MAXA ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

long long tree[MAXA + 10];

int lb(int x) { return x & (-x); }

void add(int pos, long long val) {
    for (; pos <= MAXA; pos += lb(pos)) tree[pos] = (tree[pos] + val) % MOD;
}

long long query(int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret = (ret + tree[pos]) % MOD;
    return ret;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        long long t = (query(x) + 1) * x % MOD;
        t -= query(x) - query(x - 1);
        t = (t % MOD + MOD) % MOD;
        add(x, t);
    }
    printf("%lld\n", query(MAXA));
    return 0;
}
