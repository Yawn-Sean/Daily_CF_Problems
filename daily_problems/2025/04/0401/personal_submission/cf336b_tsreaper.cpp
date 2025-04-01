#include <bits/stdc++.h>
using namespace std;

double calc(int x) {
    if (x == 0) return 0;
    double ret = 1 + sqrt(2) / 2;
    if (x == 1) return ret;
    ret += 1LL * (x - 1) * x / 2 + sqrt(2) * (x - 1);
    return ret;
}

int main() {
    int n, R; scanf("%d%d", &n, &R);

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += calc(i - 1);
        ans += calc(n - i);
        ans += 1;
    }
    printf("%.12f\n", ans / n / n * R * 2);
    return 0;
}
