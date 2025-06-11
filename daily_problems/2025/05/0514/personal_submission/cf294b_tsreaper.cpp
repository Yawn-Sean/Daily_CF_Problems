#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, sz[3];
vector<int> vec[3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec[x].push_back(y);
    }
    for (int i = 1; i <= 2; i++) {
        sz[i] = vec[i].size();
        sort(vec[i].begin(), vec[i].end(), greater<int>());
        vec[i].push_back(0);
        for (int j = sz[i] - 1; j >= 0; j--) vec[i][j] += vec[i][j + 1];
    }

    int ans = 1e9;
    for (int i = 0; i <= sz[1]; i++) for (int j = 0; j <= sz[2]; j++) {
        int tot = i + j * 2;
        if (vec[1][i] + vec[2][j] <= tot) ans = min(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
