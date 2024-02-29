#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXX ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[MAXN + 10];
long long ans;

vector<int> fac[MAXX + 10];
int cnt[MAXX + 10];

long long power(long long a, int b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        cnt[A[i]]++;
        mx = max(mx, A[i]);
    }

    for (int i = 1; i <= mx; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= mx; i++) for (int j = i; j <= mx; j += i) fac[j].push_back(i);

    for (int i = 1; i <= mx; i++) {
        int sz = fac[i].size();
        long long prod = 1;
        for (int j = 1, last = 1; j < sz; last = fac[i][j], j++)
            prod = prod * power(j, cnt[fac[i][j] - 1] - cnt[last - 1]) % MOD;
        int num = cnt[mx] - cnt[i - 1];
        long long tmp = prod * power(sz, num) % MOD;
        tmp = (tmp - prod * power(sz - 1, num) % MOD + MOD) % MOD;
        ans = (ans + tmp) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
