#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, K, A[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    if (K == 0) {
        printf("%d\n", A[n] - A[1]);
        return 0;
    }

    int L = 0, R = n + 1;
    long long sl = 0, sr = 0;
    while (K > 0 && L < R) {
        if (sl == 0) {
            L++;
            sl = 1LL * (A[L + 1] - A[L]) * L;
        }
        if (sr == 0) {
            R--;
            sr = 1LL * (A[R] - A[R - 1]) * (n + 1 - R);
        }
        long long stp = min({1LL * K, sl, sr});
        K -= stp; sl -= stp; sr -= stp;
    }

    long long sm = 0;
    for (int i = 1; i <= n; i++) sm += A[i];
    if (L >= R) {
        if (sm % n) printf("1\n");
        else printf("0\n");
    } else {
        long long ul = 1LL * (A[L + 1] - A[L]) * L - sl;
        long long ur = 1LL * (A[R] - A[R - 1]) * (n + 1 - R) - sr;
        long long l = A[L] + ul / L, r = A[R] - ur / (n + 1 - R);
        if (l < r) printf("%lld\n", r - l);
        else if (sm % n) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
