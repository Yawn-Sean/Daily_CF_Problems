#include <bits/stdc++.h>
#define MAXN ((int) 6e4)
using namespace std;

int n, A[MAXN + 10], V[MAXN + 10];

bool check(double lim) {
    double L = -2e18, R = 2e18;
    for (int i = 1; i <= n; i++) {
        L = max(L, A[i] - lim * V[i]);
        R = min(R, A[i] + lim * V[i]);
    }
    return L <= R;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &V[i]);

    double head = 0, tail = 1e9;
    for (int tries = 1; tries <= 200; tries++) {
        double mid = (head + tail) / 2;
        if (check(mid)) tail = mid;
        else head = mid;
    }
    printf("%.9f\n", head);
    return 0;
}
