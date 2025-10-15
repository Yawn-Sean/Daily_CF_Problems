#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, q;
double P;

long long f[MAXN + 5], suml[MAXN * 4 + 5], sumr[MAXN * 4 + 5];

void add(int id, int l, int r, int ql, int qr, long long x, int y) {
    if (ql <= l && r <= qr) {
        if (l >= y) suml[id] = (suml[id] + x * f[l - y]) % MOD;
        else sumr[id] = (sumr[id] + x * f[y - r]) % MOD;
    } else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (ql <= mid) add(nxt, l, mid, ql, qr, x, y);
        if (qr > mid) add(nxt | 1, mid + 1, r, ql, qr, x, y);
    }
}

long long query(int id, int l, int r, int qpos) {
    long long ret = (suml[id] * f[qpos - l] + sumr[id] * f[r - qpos]) % MOD;
    if (l < r) {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (qpos <= mid) ret = (ret + query(nxt, l, mid, qpos)) % MOD;
        else ret = (ret + query(nxt | 1, mid + 1, r, qpos)) % MOD;
    }
    return ret;
}

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d%lf", &n, &q, &P);
    f[0] = 1; f[1] = (1 - (int) round(P * 1e6) * power(1e6, MOD - 2) % MOD + MOD) % MOD;
    for (int i = 2; i <= n; i++) f[i] = f[i - 1] * f[1] % MOD;

    while (q--) {
        char op[3]; scanf("%s", op);
        if (op[0] == '+') {
            int x, y; scanf("%d%d", &x, &y);
            if (y > 1) add(1, 1, n, 1, y - 1, x, y);
            add(1, 1, n, y, n, x, y);
        } else if (op[0] == '-') {
            int x, y; scanf("%d%d", &x, &y);
            if (y > 1) add(1, 1, n, 1, y - 1, MOD - x, y);
            add(1, 1, n, y, n, MOD - x, y);
        } else {
            int x; scanf("%d", &x);
            printf("%lld\n", query(1, 1, n, x));
        }
    }
    return 0;
}
