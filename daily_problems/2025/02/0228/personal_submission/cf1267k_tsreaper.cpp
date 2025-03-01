#include <bits/stdc++.h>
#define MAXP 20
using namespace std;

long long C[MAXP + 1][MAXP + 1];

long long calc(map<int, int> &cnt, int p) {
    long long ret = 1;
    int t = 0;
    for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        int now = max(1, it->first);
        t += p - now;
        p = now;
        ret *= C[t][it->second];
        t -= it->second;
    }
    return ret;
}

void solve() {
    long long n; scanf("%lld", &n);
    int p = 1;
    map<int, int> cnt;
    while (n > 0) {
        p++;
        cnt[n % p]++;
        n /= p;
    }

    long long ans = calc(cnt, p);
    if (cnt.count(0)) {
        cnt[0]--;
        ans -= calc(cnt, p - 1);
    }
    printf("%lld\n", ans - 1);
}

int main() {
    for (int i = 0; i <= MAXP; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
