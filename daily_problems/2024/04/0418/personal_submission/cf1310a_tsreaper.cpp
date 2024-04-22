#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;
pii A[MAXN + 10];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].second);
    sort(A + 1, A + n + 1);

    priority_queue<pii> pq;
    int now = 0, i = 1;
    while (true) {
        if (pq.empty()) {
            if (i > n) break;
            now = A[i].first;
        } else {
            now++;
        }
        while (i <= n && A[i].first <= now) pq.push(pii(A[i].second, A[i].first)), i++;
        pii p = pq.top(); pq.pop();
        ans += 1LL * p.first * (now - p.second);
    }
    printf("%lld\n", ans);
    return 0;
}
