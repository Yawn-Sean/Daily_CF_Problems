#include <bits/stdc++.h>
#define MAXN 200
#define MAXM ((int) 5e4)
#define INF ((long long) 4e18)
using namespace std;

int n, m, G, S;
array<int, 4> E[MAXM + 5];

int root[MAXN + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &G, &S);
    for (int i = 1; i <= m; i++) for (int j = 0; j < 4; j++) scanf("%d", &E[i][j]);
    sort(E + 1, E + m + 1, [&](auto &a, auto &b) {
        return a[3] < b[3];
    });

    map<int, vector<int>> mp;
    for (int i = 1; i <= m; i++) mp[E[i][2]].push_back(i);

    long long ans = INF;
    vector<int> cur;
    for (auto &p : mp) {
        vector<int> tmp;
        for (int i = 0, j = 0; i < cur.size() || j < p.second.size(); ) {
            if (j == p.second.size() || (i < cur.size() && cur[i] < p.second[j])) tmp.push_back(cur[i++]);
            else tmp.push_back(p.second[j++]);
        }

        for (int i = 1; i <= n; i++) root[i] = i;
        cur.clear();
        for (int idx : tmp) {
            int x = findroot(E[idx][0]), y = findroot(E[idx][1]);
            if (x == y) continue;
            root[x] = y;
            cur.push_back(idx);
        }
        if (cur.size() == n - 1) ans = min(ans, 1LL * G * p.first + 1LL * S * E[cur.back()][3]);
    }

    if (ans < INF) printf("%lld\n", ans);
    else printf("-1\n");
    return 0;
}
