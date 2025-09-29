#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

int main() {
    scanf("%d", &n);
    long long sm = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), sm += A[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 2; i <= n; i += 2) {
        pq.push(A[i - 1]);
        pq.push(A[i]);
        ans += pq.top(); pq.pop();
    }
    printf("%lld %lld\n", sm - ans, ans);
    return 0;
}
