#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5;
constexpr long long INF = 1e16;
int a[N];
int pre[N+1], suf[N+1];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tot += a[i];
        }
        pre[0] = INT_MAX;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = min(pre[i], a[i] - (a[i] & y));
        }
        suf[n] = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = min(suf[i + 1], a[i] - (a[i] & y));
        }
        long long ans = INF;
        for (int i = 0; i < n; i++) {
            int t = a[i] | x;
            ans = min(ans, tot - a[i] + t - min({pre[i], suf[i + 1], t - (t & y)}));
        }
        printf("%lld\n", ans);
    }
    return 0;
}

