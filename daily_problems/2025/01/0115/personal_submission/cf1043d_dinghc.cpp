#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        a[x - 1] = i;
    }
    vector<vector<int>> b(m - 1, vector<int>(n, 1));
    for (int j = 0, pre; j < m - 1; j++) {
        scanf("%d", &pre); pre -= 1;
        for (int i = 1, cur; i < n; i++) {
            scanf("%d", &cur); cur -= 1;
            if (a[pre] + 1 == a[cur]) b[j][cur] = b[j][pre] + 1;
            pre = cur;
        }
    }
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        int k = a[i] + 1;
        for (int j = 0; j < m - 1; j++) {
            k = min(k, b[j][i]);
        }
        ans += k;
    }
    printf("%lld\n", ans);
    return 0;
}

