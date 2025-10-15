#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> sectors(n);
    for (int i = 0, k; i < n; i++) {
        scanf("%d", &k);
        sectors[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &sectors[i][j]);
        }
        ranges::sort(sectors[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto& pre = sectors[(i + n - 1) % n];
        auto& cur = sectors[i];
        auto& nxt = sectors[(i + n + 1) % n];
        for (int j = 0, j1 = 0, k1 = 0, j2 = 0, k2 = 0; j < cur.size(); j++) {
            while (j1 < pre.size() && pre[j1] < cur[j]) {
                k1 += 1;
                j1 += 1;
            }
            while (j2 < nxt.size() && nxt[j2] < cur[j]) {
                k2 += 1;
                j2 += 1;
            }
            if (k1 != k2) {
                if (j) ans += 1;
                k1 = k2 = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

