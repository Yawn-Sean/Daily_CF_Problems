#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, C;
long long ans;
char MAP[3][MAXN + 5];

long long f[2][64], g[2][64];

bool check1(int col, int msk) {
    vector<int> vec;
    for (int i = 0; i < 3; i++, msk /= 4) vec.push_back(msk % 4);

    for (int i = 0; i < 3; i++) {
        if (MAP[i][col] == '.' && vec[i] == 0) return false;
        if (MAP[i][col] == 'X' && vec[i] != 0) return false;
    }

    for (int i = 0; i < 3; ) {
        if (vec[i] <= 2) i++;
        else {
            if (i == 2 || vec[i + 1] != 3) return false;
            i += 2;
        }
    }
    return true;
}

bool check2(int prv, int msk) {
    vector<int> vec1, vec2;
    for (int i = 0; i < 3; i++, prv /= 4, msk /= 4) {
        vec1.push_back(prv % 4);
        vec2.push_back(msk % 4);
    }

    for (int i = 0; i < 3; i++) {
        if (vec1[i] == 1 && vec2[i] != 2) return false;
        if (vec1[i] != 1 && vec2[i] == 2) return false;
    }
    return true;
}

void calc1(int msk) {
    if (!check1(C, msk)) return;
    for (int l = 0; l < 64; l++) if (check2(l, msk))
        for (int r = 0; r < 64; r++) if (check2(msk, r))
            ans = (ans + f[C & 1 ^ 1][l] * g[C & 1 ^ 1][r]) % MOD;
}

void calc2(int row, int msk) {
    if (!check1(C, msk)) return;
    for (int l = 0; l < 64; l++) if (check2(l, msk)) {
        int a = l;
        for (int i = 0; i < row; i++) a /= 4;
        a %= 4;

        for (int r = 0; r < 64; r++) if (check2(msk, r)) {
            int b = r;
            for (int i = 0; i < row; i++) b /= 4;
            b %= 4;

            if (a == 2 || b == 1) ans = (ans + f[C & 1 ^ 1][l] * g[C & 1 ^ 1][r]) % MOD;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) scanf("%s", MAP[i] + 1), MAP[i][0] = 'X', MAP[i][n + 1] = 'X';

    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++)
        if (MAP[i][j] == 'O') C = j;
    
    f[0][0] = 1;
    for (int i = 1; i < C; i++) {
        memset(f[i & 1], 0, sizeof(f[i & 1]));
        for (int msk = 0; msk < 64; msk++) if (check1(i, msk))
            for (int prv = 0; prv < 64; prv++) if (f[i & 1 ^ 1][prv] && check2(prv, msk))
                f[i & 1][msk] = (f[i & 1][msk] + f[i & 1 ^ 1][prv]) % MOD;
    }

    g[n & 1 ^ 1][0] = 1;
    for (int i = n; i > C; i--) {
        memset(g[i & 1], 0, sizeof(g[i & 1]));
        for (int msk = 0; msk < 64; msk++) if (check1(i, msk))
            for (int prv = 0; prv < 64; prv++) if (g[i & 1 ^ 1][prv] && check2(msk, prv))
                g[i & 1][msk] = (g[i & 1][msk] + g[i & 1 ^ 1][prv]) % MOD;
    }

    if (MAP[0][C] == 'O') {
        calc1(3 * 16 + 3 * 4);
        for (int u = 1; u <= 2; u++) for (int d = 1; d <= 2; d++) calc2(0, d * 16 + u * 4);
    } else if (MAP[2][C] == 'O') {
        calc1(3 * 4 + 3);
        for (int u = 1; u <= 2; u++) for (int d = 1; d <= 2; d++) calc2(2, d * 4 + u);
    } else {
        for (int u = 1; u <= 2; u++) for (int d = 1; d <= 2; d++)
            calc2(1, d * 16 + u);
    }
    printf("%lld\n", ans);
    return 0;
}
