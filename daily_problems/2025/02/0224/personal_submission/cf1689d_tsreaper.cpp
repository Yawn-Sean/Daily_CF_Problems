#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

pii check(int lim) {
    int la = 1 - m, ra = n - 1;
    int lb = 2, rb = n + m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'B') {
        int a = i - j, b = i + j;
        la = max(la, a - lim); ra = min(ra, a + lim);
        lb = max(lb, b - lim); rb = min(rb, b + lim);
    }
    if (la > ra || lb > rb) return {0, 0};
    else {
        for (int a = la; a <= ra; a++) for (int b = lb; b <= rb; b++) {
            if ((a + b) % 2 != 0) continue;
            int i = (a + b) / 2;
            if (i <= 0 || i > n) continue;
            int j = b - i;
            if (j <= 0 || j > m) continue;
            return {i, j};
        }
        return {0, 0};
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    
    int head = 0, tail = n + m;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid).first > 0) tail = mid;
        else head = mid + 1;
    }
    pii p = check(head);
    printf("%d %d\n", p.first, p.second);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
