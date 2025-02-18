#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<int, int> pii;

int n, X, Y;
pii A[MAXN + 10];
long long ans;

int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    sort(A + 1, A + n + 1);

    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        if (ms.empty() || *(ms.begin()) >= A[i].first) {
            ans += X;
        } else {
            auto it = prev(ms.lower_bound(A[i].first));
            ans += min(1LL * X, 1LL * (A[i].first - *it) * Y);
            ms.erase(it);
        }
        ans += 1LL * (A[i].second - A[i].first) * Y;
        ans %= MOD;
        ms.insert(A[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}
