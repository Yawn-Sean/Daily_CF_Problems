#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, K, ans[MAXN + 5];
pii A[MAXN + 5];

int main() {
    scanf("%d%*d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first), A[i].second = i;
    sort(A + 1, A + n + 1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++) {
        if (!pq.empty() && pq.top().first < A[i].first) {
            pii p = pq.top(); pq.pop();
            ans[A[i].second] = p.second;
            p.first = A[i].first + K;
            pq.push(p);
        } else {
            int t = pq.size() + 1;
            ans[A[i].second] = t;
            pq.push({A[i].first + K, t});
        }
    }

    printf("%d\n", pq.size());
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}
