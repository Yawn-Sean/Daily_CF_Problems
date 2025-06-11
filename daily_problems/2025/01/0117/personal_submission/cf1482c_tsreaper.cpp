#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, ans[MAXN + 5];
vector<int> A[MAXN + 5];

int cnt[MAXN + 5];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= m; i++) {
        int k; scanf("%d", &k);
        A[i].clear();
        while (k--) {
            int x; scanf("%d", &x);
            A[i].push_back(x);
        }
        cnt[ans[i] = A[i][0]]++;
    }

    int bad = 0;
    for (int i = 1; i <= n; i++) if (cnt[i] > (m + 1) / 2) bad = i;
    if (bad) {
        for (int i = 1; i <= m && cnt[bad] > (m + 1) / 2; i++)
            if (A[i][0] == bad && A[i].size() > 1) {
                cnt[ans[i] = A[i][1]]++;
                cnt[bad]--;
            }
        if (cnt[bad] > (m + 1) / 2) { printf("NO\n"); return; }
    }
    printf("YES\n");
    for (int i = 1; i <= m; i++) printf("%d%c", ans[i], "\n "[i < m]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
