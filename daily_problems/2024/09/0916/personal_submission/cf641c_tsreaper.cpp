#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), c != '-' && (c < '0' || c > '9'));
        int k = 1;
        if (c == '-') k = -1, c = getc();
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret * k;
    }
}

int n, q, ans[MAXN];

int main() {
    n = fast::read(); q = fast::read();
    int pos[2] = {0, 1};
    while (q--) {
        int op = fast::read();
        if (op == 1) {
            int x = fast::read();
            for (int i = 0; i < 2; i++) pos[i] = (pos[i] + x % n + n) % n;
        } else {
            for (int i = 0; i < 2; i++) pos[i] ^= 1;
        }
    }
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j += 2) ans[(pos[i] + j) % n] = i + j + 1;
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
