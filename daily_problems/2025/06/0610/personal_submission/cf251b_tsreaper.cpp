#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, K, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5], D[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    
    bool same = true;
    for (int i = 1; i <= n; i++) if (B[i] != i) { same = false; break; }
    if (same) { printf("NO\n"); return 0; }

    for (int i = 1; i <= n; i++) C[i] = i;
    int x;
    for (x = 1; x <= K; x++) {
        for (int i = 1; i <= n; i++) D[i] = C[A[i]];
        for (int i = 1; i <= n; i++) C[i] = D[i];
        bool same = true;
        for (int i = 1; i <= n; i++) if (B[i] != C[i]) { same = false; break; }
        if (same) break;
    }
    
    for (int i = 1; i <= n; i++) C[i] = i;
    int y;
    for (y = 1; y <= K; y++) {
        for (int i = 1; i <= n; i++) D[A[i]] = C[i];
        for (int i = 1; i <= n; i++) C[i] = D[i];
        bool same = true;
        for (int i = 1; i <= n; i++) if (B[i] != C[i]) { same = false; break; }
        if (same) break;
    }

    if (x > K && y > K) {
        printf("NO\n");
    } else if (x > K) {
        if (y % 2 == K % 2) printf("YES\n");
        else printf("NO\n");
    } else if (y > K) {
        if (x % 2 == K % 2) printf("YES\n");
        else printf("NO\n");
    } else if (x == 1 && y == 1) {
        if (K == 1) printf("YES\n");
        else printf("NO\n");
    } else {
        if (x % 2 == K % 2 || y % 2 == K % 2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
