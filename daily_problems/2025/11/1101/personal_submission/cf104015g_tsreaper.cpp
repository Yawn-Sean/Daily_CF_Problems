#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5], cntX[MAXN + 5], cntY[MAXN + 5];
long long ans;

long long calc(int c) {
    return 1LL * c * (c - 1) * (c - 2) / 6;
}

long long solve1() {
    long long ret = calc(n);
    for (int x = 1; x <= MAXN; x++) ret -= calc(cntX[x]);
    for (int x = 1; x <= MAXN; x++) ret -= 1LL * cntX[x] * (cntX[x] - 1) / 2 * (n - cntX[x]);
    return ret;
}

long long solve2() {
    long long ret = calc(n);
    for (int y = 1; y <= MAXN; y++) ret -= calc(cntY[y]);
    for (int y = 1; y <= MAXN; y++) ret -= 1LL * cntY[y] * (cntY[y] - 1) / 2 * (n - cntY[y]);
    return ret;
}

long long solve3() {
    long long ret = calc(n);
    for (int x = 1; x <= MAXN; x++) ret -= calc(cntX[x]);
    for (int y = 1; y <= MAXN; y++) ret -= calc(cntY[y]);
    for (int x = 1; x <= MAXN; x++) ret -= 1LL * cntX[x] * (cntX[x] - 1) / 2 * (n - cntX[x]);
    for (int y = 1; y <= MAXN; y++) ret -= 1LL * cntY[y] * (cntY[y] - 1) / 2 * (n - cntY[y]);
    for (int i = 1; i <= n; i++) ret += 1LL * (cntX[X[i]] - 1) * (cntY[Y[i]] - 1);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        cntX[X[i]]++; cntY[Y[i]]++;
    }

    printf("%lld\n", solve1() + solve2() - solve3());
    return 0;
}
