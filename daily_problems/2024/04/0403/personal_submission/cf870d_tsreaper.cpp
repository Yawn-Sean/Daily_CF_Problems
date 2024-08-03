#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, ans, P[MAXN], Q[MAXN], A[MAXN], B[MAXN];

int query(int x, int y) {
    printf("? %d %d\n", x, y); fflush(stdout);
    int z; scanf("%d", &z);
    return z;
}

bool check(int p0) {
    P[0] = p0;
    for (int i = 0; i < n; i++) {
        Q[i] = P[i] ^ A[i];
        P[(i + 1) % n] = Q[i] ^ B[i];
    }
    if (P[0] != p0) return false;
    for (int i = 0; i < n; i++) if (P[Q[i]] != i) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) A[i] = query(i, i);
    for (int i = 0; i < n; i++) B[i] = query((i + 1) % n, i);

    int good;
    for (int i = 0; i < n; i++) if (check(i)) ans++, good = i;
    check(good);
    printf("!\n%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d%c", P[i], "\n "[i + 1 < n]);
    fflush(stdout);
    return 0;
}
