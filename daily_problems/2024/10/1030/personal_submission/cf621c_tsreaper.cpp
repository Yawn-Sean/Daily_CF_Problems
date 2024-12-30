#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, P, L[MAXN + 10], R[MAXN + 10];
double ans;

double calc(int l, int r) {
    return 1.0 * (r / P - (l - 1) / P) / (r - l + 1);
}

int main() {
    scanf("%d%d", &n, &P);
    for (int i = 0; i < n; i++) scanf("%d%d", &L[i], &R[i]);
    for (int i = 0; i < n; i++) {
        double p1 = calc(L[i], R[i]), p2 = calc(L[(i + 1) % n], R[(i + 1) % n]);
        double p = 1 - (1 - p1) * (1 - p2);
        ans += 2000 * p;
    }
    printf("%.12f\n", ans);
    return 0;
}
