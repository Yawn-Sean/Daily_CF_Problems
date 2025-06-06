#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long K; scanf("%d%lld", &n, &K);
    
    if (K == 3) {
        if (n <= 2) printf("NO\n");
        else printf("YES %d\n", n - 1);
    } else {
        long long now = 0;
        for (int i = n; i > 0; i--) {
            long long det = 1LL << (n - i);
            det *= det;
            if (now + det >= K) {
                long long t = 1LL << (n - i);
                t += t - 1;
                if (K - now >= t) printf("YES %d\n", i - 1);
                else printf("YES %d\n", i);
                return;
            } else {
                now += det;
            }
        }
        printf("NO\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
