#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
#define MAXQ ((int) 2e5)
#define MAXP 20
using namespace std;
typedef pair<int, int> pii;

int n, m, q, A[MAXN + 10], B[MAXM + 10];
char ans[MAXQ + 10];

int mp[MAXN + 10];
vector<pii> qry[MAXM + 10];

int last[MAXN + 10], f[MAXN + 10], g[MAXN + 10][MAXP];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mp[A[i]] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &B[i]);
        B[i] = mp[B[i]];
    }

    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        qry[r].push_back(pii(l, i));
    }

    multiset<int> ms;
    for (int i = 1; i <= n; i++) ms.insert(0);
    for (int i = 1; i <= m; i++) {
        int x = B[i], y = (x == 1 ? n : x - 1);
        g[i][0] = last[y];
        for (int p = 1; p < MAXP; p++) g[i][p] = g[g[i][p - 1]][p - 1];
        int t = i;
        for (int p = MAXP - 1; p >= 0; p--) if ((n - 1) >> p & 1) t = g[t][p];
        ms.erase(ms.find(f[x]));
        ms.insert(f[x] = t);
        last[x] = i;

        int best = *prev(ms.end());
        for (pii p : qry[i]) {
            if (p.first <= best) ans[p.second] = '1';
            else ans[p.second] = '0';
        }
    }
    printf("%s\n", ans + 1);
    return 0;
}
