#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];

void gao(int base) {
    int t = n - base + 1;
    for (int i = base; i <= n; i++) B[i - base] = A[i];
    sort(B, B + t);
    for (int i = 0; i < t; i++) C[B[i]] = i;

    int x = (C[A[base]] + t / 2) % t;
    x = B[x];

    for (int i = base + 1; i <= n; i++) B[i - base - 1] = A[i];
    sort(B, B + t - 1);
    for (int i = 0; i + 1 < t; i++) C[B[i]] = i;
    for (int i = base + 1; i <= n; i++) A[i] = C[A[i]];

    for (int i = 1, j = 0; i <= n; i++) if (i != x && i != A[base - 1]) C[j++] = i;
    for (int i = base + 1; i <= n; i++) A[i] = C[A[i]];
    A[base] = x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    if (n & 1) {
        for (int i = 2; i <= n; i++) B[i - 1] = A[i];
        sort(B + 1, B + n);
        for (int i = 1; i < n; i++) C[B[i]] = i;
        for (int i = 2; i <= n; i++) B[i] = C[A[i]];

        int x = (A[1] - 1 + n / 2) % n;
        if (B[2] > n / 2) x = (x + 1) % n;
        x++;

        A[1] = x;
        for (int i = 1, j = 1; i <= n; i++) if (i != x) C[j++] = i;
        for (int i = 2; i <= n; i++) A[i] = C[B[i]];

        gao(2);
    } else {
        gao(1);
    }

    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
