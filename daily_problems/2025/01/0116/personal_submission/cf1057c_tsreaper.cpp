#include <bits/stdc++.h>
#define MAXN 50
#define MAXK 2000
#define MAXA 50
using namespace std;

int n, S, K, ans, A[MAXN + 5], B[MAXN + 5];
char s[MAXN + 5];

int dis[MAXN * (MAXK + 1) * (MAXA + 1) * 3 + 5];

int idx(int pos, int tot, int last, int c) {
    return pos * (K + 1) * (MAXA + 1) * 3 + tot * (MAXA + 1) * 3 + last * 3 + c;
}

void unidx(int msk, int &pos, int &tot, int &last, int &c) {
    c = msk % 3; msk /= 3;
    last = msk % (MAXA + 1); msk /= MAXA + 1;
    tot = msk % (K + 1); msk /= K + 1;
    pos = msk;
}

void bfs() {
    for (int i = 0; i < n * (K + 1) * (MAXA + 1) * 3; i++) dis[i] = -1;

    queue<int> q;
    int bgn = idx(S, 0, 0, 0);
    q.push(bgn); dis[bgn] = 0;

    while (!q.empty()) {
        int msk = q.front(); q.pop();
        int pos, tot, last, c; unidx(msk, pos, tot, last, c);

        auto update = [&](int nxt, int val) {
            if (dis[nxt] >= 0) return;
            dis[nxt] = dis[msk] + val;
            q.push(nxt);
        };

        if (A[pos] > last && (last == 0 || B[pos] != c)) update(idx(pos, min(K, tot + A[pos]), A[pos], B[pos]), 0);
        if (pos > 0) update(idx(pos - 1, tot, last, c), 1);
        if (pos + 1 < n) update(idx(pos + 1, tot, last, c), 1);
    }
}

int main() {
    scanf("%d%d%d", &n, &S, &K); S--;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') B[i] = 0;
        else if (s[i] == 'G') B[i] = 1;
        else B[i] = 2;
    }

    bfs();
    ans = -1;
    for (int i = 0; i < n; i++) for (int j = 1; j <= MAXA; j++) for (int k = 0; k < 3; k++) {
        int t = dis[idx(i, K, j, k)];
        if (t == -1) continue;
        if (ans == -1 || ans > t) ans = t;
    }
    printf("%d\n", ans);
    return 0;
}
