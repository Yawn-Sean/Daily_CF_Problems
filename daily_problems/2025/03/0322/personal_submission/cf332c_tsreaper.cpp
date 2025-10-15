#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<long long, long long> pll;

int n, P, K;
array<int, 3> A[MAXN + 5];

long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &P, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        A[i][2] = i;
    }

    sort(A + 1, A + n + 1, [&](array<int, 3> &a, array<int, 3> &b) {
        if (a[1] != b[1]) return a[1] > b[1];
        else return a[0] < b[0];
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sm = 0;
    for (int i = 1; i <= K; i++) pq.push(A[i][0]), sm += A[i][0];
    for (int i = K; ; i++) {
        f[i] = sm;
        if (i == n) break;
        pq.push(A[i + 1][0]); sm += A[i + 1][0];
        sm -= pq.top(); pq.pop();
    }

    while (!pq.empty()) pq.pop();
    sm = 0;
    for (int i = n; i > n - (P - K); i--) pq.push(A[i][1]), sm += A[i][1];
    for (int i = n - (P - K) + 1; ; i--) {
        g[i] = sm;
        if (i == 1) break;
        pq.push(A[i - 1][1]); sm += A[i - 1][1];
        sm -= pq.top(); pq.pop();
    }

    int best = K;
    for (int i = K; i <= n - (P - K); i++) if (pll(f[best], g[best + 1]) < pll(f[i], g[i + 1])) best = i;

    sort(A + 1, A + best + 1, [&](array<int, 3> &a, array<int, 3> &b) {
        return a[0] > b[0];
    });
    for (int i = 1; i <= K; i++) printf("%d ", A[i][2]);
    sort(A + best + 1, A + n + 1, [&](array<int, 3> &a, array<int, 3> &b) {
        return a[1] > b[1];
    });
    for (int i = 1; i <= P - K; i++) printf("%d ", A[best + i][2]);
    printf("\n");
    return 0;
}
