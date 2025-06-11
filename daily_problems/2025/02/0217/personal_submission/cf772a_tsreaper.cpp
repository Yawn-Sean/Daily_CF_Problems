#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 5], B[MAXN + 5];

bool check(long double lim) {
    long double tot = 0;
    for (int i = 1; i <= n; i++) tot += max((long double) 0, A[i] - B[i] / lim);
    return tot <= K;
}

int main() {
    scanf("%d%d", &n, &K);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i], &B[i]);
        sm += A[i];
    }
    if (K >= sm) { printf("-1\n"); return 0; }

    long double head = 0, tail = 1e18;
    for (int i = 1; i <= 100; i++) {
        long double mid = (head + tail) / 2;
        if (check(mid)) head = mid;
        else tail = mid;
    }
    printf("%.12Lf\n", (head + tail) / 2);
    return 0;
}
