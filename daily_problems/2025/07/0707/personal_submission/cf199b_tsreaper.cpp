#include <bits/stdc++.h>
using namespace std;

int A[2][4];

int dis2(int *P, int *Q) {
    return (P[0] - Q[0]) * (P[0] - Q[0]) + (P[1] - Q[1]) * (P[1] - Q[1]);
}

bool inside(int *P, int R1, int *Q, int R2) {
    return R1 <= R2 && dis2(P, Q) <= (R1 - R2) * (R1 - R2);
}

bool outside(int *P, int R1, int *Q, int R2) {
    return dis2(P, Q) >= (R1 + R2) * (R1 + R2);
}

int main() {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 4; j++) scanf("%d", &A[i][j]);

    int ans = 0;
    for (int i = 0; i < 2; i++) for (int j = 2; j <= 3; j++) {
        bool u = inside(A[i], A[i][j], A[i ^ 1], A[i ^ 1][2]);
        bool v = outside(A[i], A[i][j], A[i ^ 1], A[i ^ 1][3]);
        bool w = inside(A[i ^ 1], A[i ^ 1][3], A[i], A[i][j]);
        if (u || v || w) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
