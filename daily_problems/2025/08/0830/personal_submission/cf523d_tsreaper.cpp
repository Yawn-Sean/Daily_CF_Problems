#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <= K; i++) pq.push(0);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        long long t = pq.top(); pq.pop();
        t = max(t, 1LL * x);
        printf("%lld\n", t + y);
        pq.push(t + y);
    }
    return 0;
}
