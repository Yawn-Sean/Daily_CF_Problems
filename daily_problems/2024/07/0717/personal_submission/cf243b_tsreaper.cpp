#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, H, T;

vector<int> e[MAXN + 10];
int deg[MAXN + 10];

int cnt[MAXN + 10];

int main() {
    scanf("%d%d%d%d", &n, &m, &H, &T);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int sn = 1; sn <= n; sn++) if (deg[sn] > H)
        for (int fn : e[sn]) if (deg[fn] > T) {
            auto &v1 = e[sn], v2 = e[fn];
            for (int i = 0; i < H + T && i < v1.size(); i++) if (v1[i] != fn) cnt[v1[i]]++;
            for (int i = 0; i < H + T && i < v2.size(); i++) if (v2[i] != sn) cnt[v2[i]]++;
            vector<int> L, R;
            for (int i = 0; i < H + T && i < v1.size(); i++) if (cnt[v1[i]] == 1) L.push_back(v1[i]);
            for (int i = 0; i < H + T && i < v2.size(); i++) if (cnt[v2[i]] == 1) R.push_back(v2[i]);
            for (int i = 0; i < H + T && i < v1.size(); i++) if (cnt[v1[i]] == 2) {
                if (L.size() < H) L.push_back(v1[i]);
                else if (R.size() < T) R.push_back(v1[i]);
            }
            if (L.size() >= H && R.size() >= T) {
                printf("YES\n%d %d\n", sn, fn);
                for (int i = 0; i < H; i++) printf("%d ", L[i]);
                printf("\n");
                for (int i = 0; i < T; i++) printf("%d ", R[i]);
                printf("\n");
                return 0;
            }
            for (int i = 0; i < H + T && i < v1.size(); i++) cnt[v1[i]] = 0;
            for (int i = 0; i < H + T && i < v2.size(); i++) cnt[v2[i]] = 0;
        }
    printf("NO\n");
    return 0;
}
