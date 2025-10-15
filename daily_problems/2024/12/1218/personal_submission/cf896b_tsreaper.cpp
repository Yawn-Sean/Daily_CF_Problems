#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, K, A[MAXN + 5];

void gao(int x, int pos) {
    printf("%d\n", pos); fflush(stdout);
    A[pos] = x;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    A[n + 1] = K + 1;
    int L = 1, R = n;
    while (L <= R) {
        int x; scanf("%d", &x);
        if (x <= K / 2) {
            for (int i = L; i > 0; i--) if (x >= A[i - 1]) {
                gao(x, i);
                if (i == L) L++;
                break;
            }
        } else {
            for (int i = R; i <= n; i++) if (x <= A[i + 1]) {
                gao(x, i);
                if (i == R) R--;
                break;
            }
        }
    }
    return 0;
}
