#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAXQ ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, q, A[MAXN + 10];
long long ans[MAXQ + 10];

vector<pii> QRY[MAXN + 10];
long long f[MAXN + 10];

void gao1(int K) {
    for (int i = n; i > 0; i--) {
        f[i] = A[i];
        if (i + K <= n) f[i] += f[i + K];
    }
    for (pii p : QRY[K]) ans[p.second] = f[p.first];
}

void gao2(int K) {
    for (pii p : QRY[K]) for (int i = p.first; i <= n; i += K)
        ans[p.second] += A[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        QRY[y].push_back({x, i});
    }

    for (int i = 1; i <= n; i++) {
        if (1LL * i * i <= n) gao1(i);
        else gao2(i);
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}
