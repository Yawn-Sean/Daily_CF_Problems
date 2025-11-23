#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define BASE ((int) 1e4)
#define MOD ((long long) 1e18 + 350234007)
using namespace std;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), (c < '0' || c > '9') && c != '-');
        bool neg = false;
        if (c == '-') neg = true, c = getc();
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret * (neg ? -1 : 1);
    }
}

int n, m, ans1, ans2, A[MAXN + 5], B[MAXN + 5], cnt[BASE + 5];

__int128 P[MAXN + 5], H[MAXN + 5];

int main() {
    n = fast::read(); m = fast::read();
    for (int i = 1; i <= n; i++) A[i] = fast::read();
    for (int i = 1; i <= m; i++) B[i] = fast::read();

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
    for (int i = 2; i <= n; i++) {
        int det = (A[i] - A[i - 1] + BASE) % BASE;
        H[i] = (H[i - 1] * BASE + det) % MOD;
    }
    __int128 goal = 0;
    for (int i = 2; i <= m; i++) {
        int det = (B[i] - B[i - 1] + BASE) % BASE;
        goal = (goal * BASE + det) % MOD;
    }

    for (int i = 1; i + m - 1 <= n; i++) {
        int det = (B[1] - A[i] + BASE) % BASE;
        __int128 h = (H[i + m - 1] - H[i] * P[m - 1] % MOD + MOD) % MOD;
        if (h == goal) cnt[det]++;
    }
    for (int i = 0; i < BASE; i++) if (cnt[i] > ans2) ans1 = i, ans2 = cnt[i];
    printf("%d %d\n", ans1, ans2);
    return 0;
}
