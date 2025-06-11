#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), c < '0' || c > '9');
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret;
    }
}

int n, q, A[MAXN + 10][MAXN + 10];

int main() {
    n = fast::read();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) A[i][j] = fast::read();
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans ^= A[i][j] & A[j][i];
    q = fast::read();
    while (q--) {
        int op = fast::read();
        if (op <= 2) {
            fast::read();
            ans ^= 1;
        } else {
            printf("%d", ans);
        }
    }
    printf("\n");
    return 0;
}
