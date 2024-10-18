#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, K, A[MAXN + 10], B[MAXN + 10];
long long ans;

list<int>::iterator ptr[MAXN + 10];
bool flag[MAXN + 10];

void solve() {
    scanf("%d%d", &n, &K);
    list<int> lst;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        lst.push_back(A[i]);
    }
    for (auto it = lst.begin(); it != lst.end(); it++) ptr[*it] = it;
    memset(flag, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= K; i++) {
        scanf("%d", &B[i]);
        flag[B[i]] = true;
    }

    ans = 1;
    for (int i = 1; i <= K; i++) {
        auto it = ptr[B[i]];
        int msk = 0;
        if (it != lst.begin() && !flag[*prev(it)]) msk |= 1;
        if (next(it) != lst.end() && !flag[*next(it)]) msk |= 2;
        if (msk == 0) { printf("0\n"); return; }
        ans = ans * (msk == 3 ? 2 : 1) % MOD;
        if (msk & 1) lst.erase(prev(it));
        else lst.erase(next(it));
        flag[B[i]] = false;
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
