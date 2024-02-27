#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXQ 1000
#define MAGIC ((int) 4e7)
using namespace std;

int n, q, OP[MAXQ + 10][3];
char s[MAXN + 10];

int cnt[5] = {1, 1, 1}, pa[3][MAXQ + 10], ch[3][MAXQ + 10];

int nxt[MAXN + 10][26], f[MAGIC];

int main() {
    scanf("%d%d%s", &n, &q, s + 1);
    int now[] = {0, 0, 0};
    for (int i = 1; i <= q; i++) {
        char op[3];
        int idx;
        scanf("%s%d", op, &idx);
        idx--;

        if (op[0] == '+') {
            char tmp[3]; scanf("%s", tmp);
            pa[idx][cnt[idx]] = now[idx];
            ch[idx][cnt[idx]] = tmp[0] - 'a';
            now[idx] = cnt[idx]++;
        } else {
            now[idx] = pa[idx][now[idx]];
        }
        for (int j = 0; j < 3; j++) OP[i][j] = now[j];
    }

    for (int j = 0; j < 26; j++) nxt[n + 1][j] = n + 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }

    int tot = cnt[0] * cnt[1] * cnt[2];
    f[0] = 0;
    for (int msk = 1; msk < tot; msk++) {
        f[msk] = n + 1;
        for (int idx = 0, p = 1; idx < 3; p *= cnt[idx], idx++) {
            int pos = msk / p % cnt[idx];
            if (pos > 0) {
                int last = msk - pos * p + pa[idx][pos] * p;
                if (f[last] <= n) f[msk] = min(f[msk], nxt[f[last] + 1][ch[idx][pos]]);
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int msk = 0;
        for (int idx = 0, p = 1; idx < 3; p *= cnt[idx], idx++)
            msk += OP[i][idx] * p;
        if (f[msk] <= n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
