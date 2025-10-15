#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> d(m);
    vector<int> h(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &d[i], &h[i]);
    }
    int ans = max(h[0] + d[0] - 1, h[m - 1] + (n - d[m - 1]));
    for (int i = 0; i < m - 1; i += 1) {
        if (abs(h[i + 1] - h[i]) > d[i + 1] - d[i]) {
            printf("IMPOSSIBLE\n");
            return 0;
        } else {
            int ds = d[i + 1] - d[i];
            ds -= abs(h[i + 1] - h[i]);
            ans = max(ans, max(h[i + 1], h[i]) + ds / 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}

