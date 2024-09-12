#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
using namespace std;
typedef pair<int, int> pii;

int m, n, A[MAXN + 10][MAXM + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);

    vector<int> ans;
    for (int who = 1; who < m; who++) {
        vector<pii> vec;
        for (int i = 1; i <= n; i++) vec.push_back({A[i][who] - A[i][m], i});
        sort(vec.begin(), vec.end(), greater<pii>());
        int sm = 0, lim = n;
        for (int i = 0; i < vec.size(); i++) {
            sm += vec[i].first;
            if (sm < 0) { lim = i; break; }
        }
        if (lim > ans.size()) {
            ans.clear();
            for (int i = 0; i < lim; i++) ans.push_back(vec[i].second);
        }
    }

    for (int x : ans) vis[x] = true;
    printf("%d\n", n - ans.size());
    for (int i = 1; i <= n; i++) if (!vis[i]) printf("%d ", i);
    printf("\n");
    return 0;
}
