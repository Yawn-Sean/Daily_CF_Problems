#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 20
#define INF ((long long) 2e18)
using namespace std;

int n, m, B, X[MAXN + 10], K[MAXN + 10], M[MAXN + 10];
long long ans;

long long f[2][1 << MAXM];

void update(long long &a, long long b) { a = min(a, b); }

int main() {
    scanf("%d%d%d", &n, &m, &B);
    for (int i = 1; i <= n; i++) {
        int t; scanf("%d%d%d", &X[i], &K[i], &t);
        while (t--) {
            int x; scanf("%d", &x);
            M[i] |= 1 << (x - 1);
        }
    }

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return K[a] < K[b];
    });

    ans = INF;
    for (int msk = 0; msk < (1 << m); msk++) f[0][msk] = INF;
    f[0][0] = 0;
    int p = 0;
    for (int idx : ord) {
        for (int msk = 0; msk < (1 << m); msk++) f[p ^ 1][msk] = INF;
        for (int msk = 0; msk < (1 << m); msk++) {
            update(f[p ^ 1][msk | M[idx]], f[p][msk] + X[idx]);
            update(f[p ^ 1][msk], f[p][msk]);
        }
        ans = min(ans, f[p ^ 1][(1 << m) - 1] + 1LL * B * K[idx]);
        p ^= 1;
    }
    printf("%lld\n", ans < INF ? ans : -1);
    return 0;
}
