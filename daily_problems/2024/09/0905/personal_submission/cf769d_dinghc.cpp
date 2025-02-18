#include <bits/stdc++.h>

using namespace std;
const int N = 10000;
int cnt[N + 1];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    long long ans = 0LL;
    if (k == 0) {
        for (int a = 0; a <= N; a++) {
            ans += 1LL * cnt[a] * (cnt[a] - 1) / 2;
        }
    } else {
        for (int a = 0; a <= N; a++) {
            for (int b = a + 1; b <= N; b++) {
                if (__builtin_popcount(a ^ b) == k) {
                    ans += 1LL * cnt[a] * cnt[b];
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

