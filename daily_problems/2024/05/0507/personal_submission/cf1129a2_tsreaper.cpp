#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, m;
int A[MAXN + 10], B[MAXN + 10], C[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) B[i] = n;

    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        A[x]++;
        int det = (y - x + n) % n;
        B[x] = min(B[x], det);
    }

    multiset<int> ms;
    for (int i = 0; i < n; i++) if (A[i] > 0) {
        C[i] = (A[i] - 1) * n + B[i] + i;
        ms.insert(C[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", *prev(ms.end()) - i, "\n "[i + 1 < n]);
        if (C[i] > 0) {
            ms.erase(ms.find(C[i]));
            C[i] += n;
            ms.insert(C[i]);
        }
    }
    return 0;
}
