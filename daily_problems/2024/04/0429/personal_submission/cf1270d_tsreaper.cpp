#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, K;

int main() {
    scanf("%d%d", &n, &K);

    printf("?");
    for (int i = 1; i <= K; i++) printf(" %d", i);
    printf("\n"); fflush(stdout);
    int pa, va; scanf("%d%d", &pa, &va);

    printf("?");
    for (int i = 1; i <= K + 1; i++) if (i != pa) printf(" %d", i);
    printf("\n"); fflush(stdout);
    int pb, vb; scanf("%d%d", &pb, &vb);

    int diff = 0;
    for (int i = 1; i <= K + 1; i++) if (i != pa && i != pb) {
        printf("?");
        for (int j = 1; j <= K + 1; j++) if (i != j) printf(" %d", j);
        printf("\n"); fflush(stdout);
        int pt, vt; scanf("%d%d", &pt, &vt);
        if (pt != pa) diff++;
    }

    if (va < vb) printf("! %d\n", diff + 1);
    else printf("! %d\n", K - diff);
    fflush(stdout);
    return 0;
}
