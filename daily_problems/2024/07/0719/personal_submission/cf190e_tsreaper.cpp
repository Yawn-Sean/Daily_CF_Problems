#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, m;

vector<int> e[MAXN + 10], block[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end(), greater<int>());

    list<int> lst;
    for (int i = 1; i <= n; i++) lst.push_back(i);
    while (!lst.empty()) {
        int x = lst.front(); lst.pop_front();
        queue<int> q;
        q.push(x);
        while (!q.empty()) {
            int sn = q.front(); q.pop();
            block[x].push_back(sn);
            for (auto it = lst.begin(); it != lst.end(); ) {
                int fn = *it;
                while (!e[sn].empty() && e[sn].back() < fn) e[sn].pop_back();
                if (!e[sn].empty() && e[sn].back() == fn) { it++; continue; }
                q.push(fn);
                it = lst.erase(it);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (block[i].size() > 0) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) if (block[i].size() > 0) {
        printf("%d", block[i].size());
        for (int x : block[i]) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
