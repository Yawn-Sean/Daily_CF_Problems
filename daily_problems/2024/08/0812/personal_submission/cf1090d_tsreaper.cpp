#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int A[MAXN + 10], B[MAXN + 10];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    if (n == 1 || m == 1LL * n * (n - 1) / 2) { printf("NO\n"); return 0; }

    set<pii> st;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        st.insert({x, y}); st.insert({y, x});
    }
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (!st.count({i, j})) {
        printf("YES\n");
        A[i] = B[i] = B[j] = 1; A[j] = 2;
        for (int k = 1, t = 3; k <= n; k++) if (A[k] == 0) A[k] = B[k] = t++;
        for (int k = 1; k <= n; k++) printf("%d%c", A[k], "\n "[k < n]);
        for (int k = 1; k <= n; k++) printf("%d%c", B[k], "\n "[k < n]);
        return 0;
    }
    return 0;
}
