#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    for (int i = 1; i <= n; i++) {
        unordered_map<int, unordered_map<int, int>> mp;
        for (int j = 1; j <= n; j++) if (i != j) {
            int dx = X[j] - X[i], dy = Y[j] - Y[i];
            bool flag = false;
            if (dx * dy < 0) flag = true;
            dx = abs(dx); dy = abs(dy);
            int g = gcd(dx, dy);
            mp[dx / g * (flag ? -1 : 1)][dy / g]++;
        }
        for (auto &p1 : mp) for (auto &p2 : p1.second) ans += 1LL * p2.second * (n - 1 - p2.second);
    }
    printf("%lld\n", ans / 6);
    return 0;
}
