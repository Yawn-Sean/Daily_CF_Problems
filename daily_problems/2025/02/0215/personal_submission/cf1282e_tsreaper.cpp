#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5][3];
vector<int> ans1[MAXN + 5], ans2;

unordered_set<int> st[MAXN + 5], ban[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) st[i].clear();
    for (int i = 1; i <= n - 2; i++) for (int j = 0; j < 3; j++) {
        scanf("%d", &A[i][j]);
        st[A[i][j]].insert(i);
    }

    for (int i = 1; i <= n; i++) ans1[i].clear(), ban[i].clear();
    ans2.clear();
    queue<int> q;
    for (int i = 1; i <= n; i++) if (st[i].size() == 1) q.push(i);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (st[x].empty()) continue;
        int idx = *(st[x].begin());
        ans2.push_back(idx);

        vector<int> tmp;
        for (int i = 0; i < 3; i++) {
            int y = A[idx][i];
            if (x != y) tmp.push_back(y);
        }
        for (int y : tmp) {
            if (ban[x].count(y)) continue;
            ans1[x].push_back(y);
            ans1[y].push_back(x);
        }
        if (ans2.size() == n - 2) {
            ans1[tmp[0]].push_back(tmp[1]);
            ans1[tmp[1]].push_back(tmp[0]);
        } else {
            ban[tmp[0]].insert(tmp[1]);
            ban[tmp[1]].insert(tmp[0]);
        }

        for (int i = 0; i < 3; i++) {
            int y = A[idx][i];
            st[y].erase(idx);
            if (st[y].size() == 1) q.push(y);
        }
    }

    for (int i = 1, sn = 1, last = 0; i <= n; i++) {
        printf("%d%c", sn, "\n "[i < n]);
        for (int j = 0; j < 2; j++) if (ans1[sn][j] != last) {
            last = sn;
            sn = ans1[sn][j];
            break;
        }
    }
    for (int i = 0; i < ans2.size(); i++) printf("%d%c", ans2[i], "\n "[i + 1 < ans2.size()]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
