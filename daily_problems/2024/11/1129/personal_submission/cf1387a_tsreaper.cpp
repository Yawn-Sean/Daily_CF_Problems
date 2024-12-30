#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define EPS (1e-9)
using namespace std;

int n, m;
double ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int vk[MAXN + 5], vb[MAXN + 5];

void solve(int S) {
    double X;
    bool flag = false;

    vector<int> vec;
    auto dfs = [&](auto &&self, int sn, int K, int B) -> void {
        if (!vk[sn]) vk[sn] = K, vb[sn] = B;
        else {
            if (vk[sn] != K) {
                double x = 1.0 * (vb[sn] - B) / (K - vk[sn]);
                if (flag && fabs(X - x) > EPS) { printf("NO\n"); exit(0); }
                X = x; flag = true;
            } else if (vb[sn] != B) {
                printf("NO\n"); exit(0);
            }
            return;
        }

        vec.push_back(sn);
        for (int i = 0; i < e[sn].size(); i++)
            self(self, e[sn][i], -K, v[sn][i] - B);
    };
    dfs(dfs, S, 1, 0);

    if (!flag) {
        vector<int> tmp;
        for (int sn : vec) tmp.push_back(-vk[sn] * vb[sn]);
        sort(tmp.begin(), tmp.end());
        X = tmp[tmp.size() / 2];
    }
    for (int sn : vec) ans[sn] = X * vk[sn] + vb[sn];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }
    for (int i = 1; i <= n; i++) if (!vk[i]) solve(i);
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%.12f%c", ans[i], "\n "[i < n]);
    return 0;
}
