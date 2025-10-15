#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int main() {
    int n; scanf("%d", &n);

    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        x -= min(i - 1, n - i);
        if (x > 0) mp[x]++;
    }

    int mx = 0;
    for (auto &p : mp) mx = max(mx, p.second);
    printf("%d\n", n - mx);
    return 0;
}
