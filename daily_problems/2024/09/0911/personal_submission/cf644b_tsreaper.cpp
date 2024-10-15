#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, A[MAXN + 10], B[MAXN + 10];
long long ans[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);

    int idx = 1;
    long long now = 0;
    queue<int> q;
    while (true) {
        while (idx <= n && A[idx] < now) {
            if (q.size() < K) q.push(idx);
            else ans[idx] = -1;
            idx++;
        }
        if (q.empty()) {
            if (idx > n) break;
            q.push(idx);
            now = A[idx];
            idx++;
        }
        int t = q.front(); q.pop();
        now += B[t];
        ans[t] = now;
    }

    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}
