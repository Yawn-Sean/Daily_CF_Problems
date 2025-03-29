#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q, A[MAXN + 5];
long long OP[MAXN + 5][4];

int main() {
    scanf("%d", &n);

    long long now = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &OP[i][0]);
        if (OP[i][0] == 1) {
            scanf("%lld", &OP[i][1]);
            OP[i][3] = ++now;
        } else {
            scanf("%lld%lld", &OP[i][1], &OP[i][2]);
            now += 1LL * OP[i][1] * OP[i][2];
            OP[i][3] = now;
        }
    }

    now = 0;
    for (int i = 1; i <= n && now <= MAXN; i++) {
        if (OP[i][0] == 1) A[++now] = OP[i][1];
        else {
            for (int j = 1; j <= OP[i][2] && now <= MAXN; j++)
                for (int k = 1; k <= OP[i][1] && now <= MAXN; k++)
                    A[++now] = A[k];
        }
    }

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        long long x; scanf("%lld", &x);
        if (x <= MAXN) printf("%d", A[x]);
        else {
            int head = 1, tail = n;
            while (head < tail) {
                int mid = (head + tail) >> 1;
                if (OP[mid][3] >= x) tail = mid;
                else head = mid + 1;
            }
            if (OP[head][0] == 1) printf("%lld", OP[head][1]);
            else {
                long long det = x - OP[head - 1][3];
                printf("%d", A[(det - 1) % OP[head][1] + 1]);
            }
        }
        printf("%c", "\n "[i < q]);
    }
    return 0;
}
