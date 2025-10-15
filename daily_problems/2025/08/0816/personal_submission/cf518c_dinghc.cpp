#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(n), pos(n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        x -= 1;
        pos[x] = i;
        a[i] = x;
    }
    long long ans = 0;
    for (int i = 0, x; i < m; i++) {
        scanf("%d", &x);
        x -= 1;
        ans += pos[x] / k + 1;
        int j = pos[x];
        if (j) {
            int y = a[j - 1];
            pos[x] = j - 1;
            pos[y] = j;
            a[j - 1] = x;
            a[j] = y;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

