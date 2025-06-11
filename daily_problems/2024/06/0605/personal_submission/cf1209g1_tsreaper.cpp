#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, ans, A[MAXN + 10];

int L[MAXN + 10], R[MAXN + 10], cnt[MAXN + 10];

int main() {
    scanf("%d%*d", &n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mp[A[i]] = 1;
    for (auto &p : mp) p.second = ++m;
    for (int i = 1; i <= n; i++) A[i] = mp[A[i]];

    for (int i = 1; i <= n; i++) {
        if (L[A[i]] == 0) L[A[i]] = i;
        R[A[i]] = i;
    }

    for (int i = 1, j = 1, lim = 0, mx = 0; i <= n; i++) {
        lim = max(lim, R[A[i]]);
        mx = max(mx, ++cnt[A[i]]);
        if (i != lim) continue;
        ans += i - j + 1 - mx;
        for (int k = j; k <= i; k++) cnt[A[k]] = 0;
        j = i + 1;
        mx = 0;
    }
    printf("%d\n", ans);
    return 0;
}
