#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
pii A[MAXN + 5];

int B[MAXN * 2 + 5], pa[MAXN * 2 + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first), A[i].second = i;
    sort(A + 1, A + n + 1, greater<pii>());

    int m = A[1].first, len = m;
    for (int i = 1; i <= m; i++) B[i] = A[i].second * 2 - 1;
    for (int i = 1; i < m; i++) pa[B[i + 1]] = B[i];
    for (int i = 1; i <= m; i++) {
        if (i + A[i].first > len) B[++len] = A[i].second * 2, pa[B[len]] = B[len - 1];
        else pa[A[i].second * 2] = B[i + A[i].first - 1];
    }

    for (int i = m + 1; i <= n; i++) {
        pa[A[i].second * 2 - 1] = B[1];
        if (A[i].first > 1) pa[A[i].second * 2] = B[A[i].first - 1];
        else pa[A[i].second * 2] = A[i].second * 2 - 1;
    }

    for (int i = 1; i <= n * 2; i++) if (pa[i]) printf("%d %d\n", pa[i], i);
    return 0;
}
