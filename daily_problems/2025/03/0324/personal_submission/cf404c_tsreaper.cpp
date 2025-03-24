#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, K;
vector<pii> ans;

vector<int> vec[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec[x].push_back(i);
    }

    if (vec[0].size() != 1) { printf("-1\n"); return 0; }
    for (int i = 1; i < n; i++) {
        long long fac = (i == 1 ? K : K - 1);
        if (vec[i].size() > vec[i - 1].size() * fac) { printf("-1\n"); return 0; }
        for (int j = 0; j < vec[i].size(); j++) ans.push_back({vec[i - 1][j / fac], vec[i][j]});
    }

    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
