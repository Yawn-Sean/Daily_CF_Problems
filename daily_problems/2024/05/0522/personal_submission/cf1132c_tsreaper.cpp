#include <bits/stdc++.h>
#define MAXN 5000
#define MAXQ 5000
using namespace std;

int n, q, ans, A[MAXQ + 10][2];

int sm[MAXN + 10], one[MAXN + 10], two[MAXN + 10];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        sm[A[i][0]]++; sm[A[i][1] + 1]--;
    }

    int base = 0;
    for (int i = 1; i <= n; i++) {
        sm[i] += sm[i - 1];
        one[i] = one[i - 1];
        two[i] = two[i - 1];
        if (sm[i] > 0) base++;
        if (sm[i] == 1) one[i]++;
        if (sm[i] == 2) two[i]++;
    }

    for (int x = 1; x <= q; x++) for (int y = x + 1; y <= q; y++) {
        int lx = min(A[x][0], A[y][0]), rx = min(A[x][1], A[y][1]);
        int ly = max(A[x][0], A[y][0]), ry = max(A[x][1], A[y][1]);
        if (rx < ly) {
            int t = base;
            t -= one[rx] - one[lx - 1];
            t -= one[ry] - one[ly - 1];
            ans = max(ans, t);
        } else {
            int t = base;
            t -= one[ly - 1] - one[lx - 1];
            t -= one[ry] - one[rx];
            t -= two[rx] - two[ly - 1];
            ans = max(ans, t);
        }
    }
    printf("%d\n", ans);
    return 0;
}
