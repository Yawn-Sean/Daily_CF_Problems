#include <bits/stdc++.h>
#define MAXB 10
#define MAXP 60
using namespace std;

vector<int> A;
long long f[MAXB + 1][MAXP][2][1 << MAXB];

long long dp(int b, int pos, int full, int bgn,int msk) {
    if (pos < 0) return msk == 0;
    long long ret = f[b][pos][bgn][msk];
    if (!full && ret >= 0) return ret;
    ret = 0;

    int R = (full ? A[pos] : b - 1);
    for (int i = 0; i <= R; i++) {
        int nxtBgn = bgn || i > 0;
        int nxtMsk = msk;
        if (nxtBgn) nxtMsk ^= 1 << i;
        ret += dp(b, pos - 1, full && i == R, nxtBgn, nxtMsk);
    }
    if (!full) f[b][pos][bgn][msk] = ret;
    return ret;
}

long long solve(long long X, int b) {
    A.clear();
    for (; X; X /= b) A.push_back(X % b);
    return dp(b, A.size() - 1, 1, 0, 0);
}

int main() {
    memset(f, -1, sizeof(f));
    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        int b;
        long long l, r;
        scanf("%d%lld%lld", &b, &l, &r);
        printf("%lld\n", solve(r, b) - solve(l - 1, b));
    }
    return 0;
}
