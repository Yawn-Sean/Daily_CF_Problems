#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;

int n, A[MAXN + 10];

int bel[MAXN + 10];

int calc() {
    for (int i = 1; i <= n; i++) bel[i] = 0;
    int ret = n, num = 0;
    for (int i = 1; i <= n; i++) if (!bel[i]) {
        ret--, num++;
        for (int j = i; !bel[j]; j = A[j]) bel[j] = num;
    }
    return ret;
}

void gao1() {
    calc();
    for (int i = 1; i <= n; i++) if (i != A[i])
        for (int j = i + 1; j <= n; j++) if (bel[i] == bel[j]) {
            printf("%d %d ", i, j);
            swap(A[i], A[j]);
            return;
        }
}

void gao2() {
    calc();
    for (int i = 2; i <= n; i++) if (bel[1] != bel[i]) {
        printf("1 %d ", i);
        swap(A[1], A[i]);
        return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int now = calc();
    int goal; scanf("%d", &goal);
    if (now >= goal) {
        printf("%d\n", now - goal);
        for (int i = 1; i <= now - goal; i++) gao1();
    } else {
        printf("%d\n", goal - now);
        for (int i = 1; i <= goal - now; i++) gao2();
    }
    printf("\n");
    return 0;
}
