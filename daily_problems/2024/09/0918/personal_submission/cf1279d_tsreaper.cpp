#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXA ((int) 1e6)
#define MOD 998244353
using namespace std;

int n;
vector<int> vec[MAXN + 10];
long long ans;

int cnt[MAXA + 10];
long long inv[MAXN + 10];

int main() {
    scanf("%d", &n);

    int smk = 0;
    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);
        smk += k;
        while (k--) {
            int x; scanf("%d", &x);
            vec[i].push_back(x);
            cnt[x]++;
        }
    }

    inv[1] = 1;
    for (int i = 2; i <= smk; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

    for (int i = 1; i <= n; i++) for (int x : vec[i])
        ans = (ans + inv[n] * inv[vec[i].size()] % MOD * cnt[x] % MOD * inv[n]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
