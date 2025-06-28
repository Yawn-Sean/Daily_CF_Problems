#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), indeg(n, 0);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        a[i] = x - 1;
        indeg[x - 1] += 1;
    }
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            printf("-1\n");
            return 0;
        }
    }
    int ans = 1;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int q = a[i];
        int cnt = 1;
        vis[i] = 1;
        while (q != i) {
            vis[q] = 1;
            cnt += 1;
            q = a[q];
        }
        if (cnt % 2 == 0) cnt /= 2;
        ans = lcm(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}

