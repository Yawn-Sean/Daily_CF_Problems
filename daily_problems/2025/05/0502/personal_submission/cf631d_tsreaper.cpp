#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m;
long long ans, A[MAXN + 5][2], B[MAXN + 5][2];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

long long MOD = 1e18 + rnd(0, 1e9);
int BASE = 1e9 + rnd(0, 1e9);

struct HashSeq {
    vector<__int128> P, H;

    HashSeq(int n, long long A[][2]) {
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + A[i][0] * 26 + A[i][1]) % MOD;
    }

    long long query(int l, int r) {
        return (H[r] - H[l - 1] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

void gao(int &n, long long A[][2]) {
    int j = 1;
    for (int i = 2; i <= n; i++) {
        if (A[i][1] == A[j][1]) A[j][0] += A[i][0];
        else j++, A[j][0] = A[i][0], A[j][1] = A[i][1];
    }
    n = j;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char c; scanf("%lld-%c", &A[i][0], &c);
        A[i][1] = c - 'a';
    }
    for (int i = 1; i <= m; i++) {
        char c; scanf("%lld-%c", &B[i][0], &c);
        B[i][1] = c - 'a';
    }
    gao(n, A); gao(m, B);

    if (m == 1) {
        for (int i = 1; i <= n; i++) if (A[i][1] == B[1][1] && A[i][0] >= B[1][0]) ans += A[i][0] - B[1][0] + 1;
    } else {
        HashSeq hs1(n, A), hs2(m, B);
        for (int i = 1; i + m - 1 <= n; i++) {
            long long x = hs1.query(i + 1, i + m - 2), y = hs2.query(2, m - 1);
            if (x == y && A[i][1] == B[1][1] && A[i][0] >= B[1][0] && A[i + m - 1][1] == B[m][1] && A[i + m - 1][0] >= B[m][0]) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
