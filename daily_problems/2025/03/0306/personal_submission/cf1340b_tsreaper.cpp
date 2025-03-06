#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

vector<string> D = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

int n, K, A[MAXN + 5], B[10];

int f[MAXN + 5][MAXN + 5];

int main() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 7; j++) B[i] = B[i] * 2 + D[i][j] - '0';

    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        char s[10]; scanf("%s", s);
        for (int j = 0; j < 7; j++) A[i] = A[i] * 2 + s[j] - '0';
    }

    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= K; j++) f[i][j] = -1;
    f[n + 1][0] = 0;
    for (int i = n; i > 0; i--) for (int d = 9; d >= 0; d--) if ((A[i] & B[d]) == A[i]) {
        int cnt = __builtin_popcount(A[i] ^ B[d]);
        for (int j = cnt; j <= K; j++) if (f[i][j] < 0 && f[i + 1][j - cnt] >= 0) f[i][j] = d;
    }

    if (f[1][K] < 0) { printf("-1\n"); return 0; }
    for (int i = 1, j = K; i <= n; i++) {
        printf("%d", f[i][j]);
        j -= __builtin_popcount(A[i] ^ B[f[i][j]]);
    }
    printf("\n");
    return 0;
}
