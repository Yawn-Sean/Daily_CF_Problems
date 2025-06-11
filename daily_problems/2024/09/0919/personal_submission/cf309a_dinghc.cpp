#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1'000'000;
int a[N * 2];

int main() {
    int n, l, t;
    scanf("%d%d%d", &n, &l, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i] + l;
    }
    double ans = 1LL * (n - 1) * n / 2 * (t / l);
    t %= l;
    long long ans2 = 0;
    if (t > 0) {
        for (int i = 0, j = 0; i < n * 2; i++) {
            while (a[i] - a[j] > t * 2) {
                j++;
            }
            if (j >= n) break;
            ans2 += min(i, n) - j;
        }
    }
    printf("%.12f\n", ans + ans2 * 0.25);
    return 0;
}

