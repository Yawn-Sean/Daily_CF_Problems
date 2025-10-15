#include <bits/stdc++.h>
#define MAXN 18
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];
vector<pii> ans;

long long f[MAXN + 5][2];
pii from[MAXN + 5][2];

void update(int i, int j, int ii, int jj, long long v) {
    if (f[i][j] < f[ii][jj] + v) {
        f[i][j] = f[ii][jj] + v;
        from[i][j] = {ii, jj};
    }
}

void gao(int l, int r) {
    if (l > r) return;
    gao(l, r - 1);
    if (A[r] != r - l) {
        ans.push_back({l, r});
        for (int i = l; i <= r; i++) A[i] = r - l;
    }
    gao(l, r - 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 0; i <= n; i++) f[i][0] = f[i][1] = -INF;
    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) update(i, 0, j - 1, 1, (i - j + 1) * (i - j + 1));
        for (int j = 0; j < 2; j++) update(i, 1, i - 1, j, A[i]);
    }

    int j = (f[n][1] > f[n][0] ? 1 : 0);
    printf("%lld ", f[n][j]);
    for (int i = n; i > 0; ) {
        pii p = from[i][j];
        if (j == 0) {
            gao(p.first + 1, i);
            ans.push_back({p.first + 1, i});
        }
        i = p.first; j = p.second;
    }
    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
