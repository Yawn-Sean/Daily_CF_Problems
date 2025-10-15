#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1 || n % 2 == 0) {
        printf("-1\n");
    } else {
        int ans = 0;
        for (int x = (n - 1) / 2; x >= 2; x--) {
            ans += max(a[x * 2], a[x * 2 + 1]);
            a[x] -= min(a[x], max(a[x * 2], a[x * 2 + 1]));
        }
        ans += max({a[1], a[2], a[3]});
        printf("%d\n", ans);
    }
    return 0;
}

