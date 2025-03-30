#include <bits/stdc++.h>
#define MAXN 75
#define MAXP 20
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, ans;
char s[MAXN + 5];

int f[MAXN + 1][1 << MAXP], nxt[MAXN + 5];

void update(int &a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
}

int main() {
    scanf("%d%s", &n, s + 1);

    vector<int> good;
    for (int i = 1; i <= MAXP; i++) good.push_back((1 << i) - 1);
    nxt[n + 1] = n + 1;
    for (int i = n; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        if (s[i] == '1') nxt[i] = i;
    }

    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
        for (int x : good) update(ans, f[i][x]);
        if (i < n) for (int msk = 0; msk < (1 << MAXP); msk++) for (int j = nxt[i + 1], v = 0; j <= n; j++) {
            v = (v << 1) | (s[j] - '0');
            if (v > MAXP) break;
            if (v > 0) update(f[j][msk | (1 << (v - 1))], f[i][msk]);
        }
        for (int msk = 0; msk < (1 << MAXP); msk++) f[i][msk] = 0;
    }
    printf("%d\n", ans);
    return 0;
}
