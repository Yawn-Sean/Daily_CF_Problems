#include <bits/stdc++.h>
#define MAXN 600
using namespace std;
typedef pair<int, int> pii;

int n, m, A[MAXN + 5][MAXN + 5];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);

    double diff = 0;
    for (int j = 1; j <= m; j++) diff += abs(A[n / 2 + 1][j] - A[n / 2][j]);
    diff /= m;
    if (diff >= 45) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
