#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int xs[N + 1];
int ds[N + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &xs[i], &ds[i]);
    }
    auto f = [&] (int x) {
        return 1LL * (n - x - 1) * (n - x) / 2 + 1LL * (x + 1) * x / 2;
    };
    long long mx = max(f(0), f(n - 1));
    long long mn = min(f((n - 1) / 2), f(n / 2));
    long long ans = 0LL;
    for (int i = 0; i < m; i++) {
        ans += xs[i] * n;
        if (ds[i] > 0) ans += ds[i] * mx;
        else ans += ds[i] * mn;
    }
    printf("%.15f\n", 1.0 * ans / n);
    return 0;
}

