#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, c;
long long A[MAXN + 5];

void solve() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);

    vector<int> ord;
    for (int i = 2; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return A[x] - 1LL * c * x > A[y] - 1LL * c * y;
    });

    for (int x : ord) {
        if (A[x] + A[1] >= 1LL * c * x) A[1] += A[x];
        else { printf("NO\n"); return; }
    }
    printf("YES\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
