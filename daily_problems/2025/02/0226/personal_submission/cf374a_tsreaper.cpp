#include <bits/stdc++.h>
#define INF ((int) 1e9)
using namespace std;

int n, m, R, C, A, B;

int gao(int i, int j) {
    int det1 = abs(R - i), det2 = abs(C - j);
    if (det1 % A > 0 || det2 % B > 0) return INF;
    int step1 = det1 / A, step2 = det2 / B;
    if (step1 % 2 != step2 % 2) return INF;
    if (step1 == 0 && step2 == 0) return 0;
    if (A >= n || B >= m) return INF;
    return max(step1, step2);
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &R, &C, &A, &B);
    int ans = min({gao(1, 1), gao(1, m), gao(n, 1), gao(n, m)});
    if (ans < INF) printf("%d\n", ans);
    else printf("Poor Inna and pony!\n");
    return 0;
}
