#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, X, K, A[MAXN + 10];

long long gao(int K) {
    long long ret = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= i && A[i] / X - (A[j] - 1) / X > K) j++;
        ret += i - j + 1;
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &X, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    long long ans = gao(K) - gao(K - 1);

    if (K <= 1) {
        unordered_map<int, int> cnt;
        for (int i = 1; i <= n; i++) cnt[A[i]]++;
        for (auto &p : cnt) if ((p.first % X == 0) == (K == 1)) ans += 1LL * p.second * (p.second - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
