#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, X[3], Y[3];

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        if (X[i] < Y[i]) swap(X[i], Y[i]);
        n = max(n, X[i]);
    }
    if (X[0] == X[1] && X[1] == X[2]) {
        if (Y[0] + Y[1] + Y[2] != X[0]) printf("-1\n");
        else {
            printf("%d\n", n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i < Y[0]) printf("A");
                    else if (i < Y[0] + Y[1]) printf("B");
                    else printf("C");
                }
                printf("\n");
            }
        }
    } else {
        int who;
        for (int i = 0; i < 3; i++) if (X[i] == n) { who = i; break; }
        int m = n - Y[who];
        for (int i = 0; i < 3; i++) if (i != who) {
            if (X[i] == m) swap(X[i], Y[i]);
            else if (Y[i] == m) continue;
            else { printf("-1\n"); return 0; }
        }
        if (X[0] + X[1] + X[2] != n * 2) printf("-1\n");
        else {
            printf("%d\n", n);
            for (int i = 0; i < Y[who]; i++) {
                for (int j = 0; j < n; j++) printf("%c", who + 'A');
                printf("\n");
            }
            int tmp;
            for (int i = 0; i < 3; i++) if (i != who) { tmp = i; break; }
            for (int i = Y[who]; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j < X[tmp]) printf("%c", tmp + 'A');
                    else printf("%c", 3 - who - tmp + 'A');
                }
                printf("\n");
            }
        }
    }
    return 0;
}
