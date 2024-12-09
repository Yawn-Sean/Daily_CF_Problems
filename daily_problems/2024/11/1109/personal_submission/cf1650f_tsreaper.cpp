#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, m, A[MAXN + 10];
vector<int> ans;

vector<array<int, 3>> vec[MAXN + 10];
long long f[101];
int from[MAXN + 1][101];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        vec[x].push_back({y, z, i});
    }

    ans.clear();
    long long now = 0;
    for (int idx = 1; idx <= n; idx++) {
        for (int j = 0; j <= 100; j++) f[j] = INF;
        f[0] = 0;
        for (int i = 1; i <= vec[idx].size(); i++) {
            auto arr = vec[idx][i - 1];
            for (int j = 100; j >= 0; j--) from[i][j] = j;
            for (int j = 99; j >= 0; j--) {
                int jj = min(100, j + arr[1]);
                if (f[jj] > f[j] + arr[0]) {
                    f[jj] = f[j] + arr[0];
                    from[i][jj] = j;
                }
            }
        }
        now += f[100];
        if (now > A[idx]) { printf("-1\n"); return; }
        vector<int> tmp;
        for (int i = vec[idx].size(), j = 100; i > 0; j = from[i][j], i--) {
            if (from[i][j] == j) continue;
            tmp.push_back(vec[idx][i - 1][2]);
        }
        while (!tmp.empty()) ans.push_back(tmp.back()), tmp.pop_back();
    }

    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
