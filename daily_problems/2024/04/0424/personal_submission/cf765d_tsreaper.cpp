#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];
int m, mp[MAXN + 10], B[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (i == A[i]) mp[i] = ++m, B[m] = i;
    }
    for (int i = 1; i <= n; i++) if (mp[A[i]] == 0) { printf("-1\n"); return 0; }
    printf("%d\n", m);
    for (int i = 1; i <= n; i++) printf("%d%c", mp[A[i]], "\n "[i < n]);
    for (int i = 1; i <= m; i++) printf("%d%c", B[i], "\n "[i < m]);
    return 0;
}
