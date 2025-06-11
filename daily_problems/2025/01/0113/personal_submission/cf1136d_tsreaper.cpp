#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, m, A[MAXN + 5];
unordered_set<int> st[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        st[x].insert(y);
    }

    int t = A[n];
    for (int i = n - 1; i > 0; i--) for (int j = i + 1; j <= n; j++) {
        if (st[A[j - 1]].count(A[j])) swap(A[j - 1], A[j]);
        else break;
    }
    for (int i = 1; i <= n; i++) if (A[i] == t) { printf("%d\n", n - i); break; }
    return 0;
}
