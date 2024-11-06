#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K;

vector<int> e[MAXN + 10];
int deg[MAXN + 10];
bool flag[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int i = 1; i <= n; i++) flag[i] = true;
    while (K--) {
        unordered_map<int, int> mp;
        vector<int> vec;
        for (int sn = 1; sn <= n; sn++) if (flag[sn] && deg[sn] == 1) vec.push_back(sn);
        for (int sn : vec) {
            flag[sn] = false;
            for (int fn : e[sn]) if (flag[fn]) {
                mp[fn]++;
                deg[fn]--;
            }
        }
        if (vec.size() < 3) { printf("No\n"); return 0; }
        for (auto &p : mp) if (deg[p.first] > 1 || p.second < 3) { printf("No\n"); return 0; }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (flag[i]) cnt++;
    if (cnt == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
