#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, A[MAXN + 5][3];
double ans;

double dis(int i, int j) {
    long long d2 = 0;
    for (int k = 0; k < 3; k++) d2 += 1LL * (A[i][k] - A[j][k]) * (A[i][k] - A[j][k]);
    return sqrt(d2);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]);
    ans = 1e200;
    for (int i = 2; i <= n; i++) for (int j = i + 1; j <= n; j++) ans = min(ans, (dis(i, j) + dis(1, i) + dis(1, j)) / 2);
    printf("%.12f\n", ans);
    return 0;
}
