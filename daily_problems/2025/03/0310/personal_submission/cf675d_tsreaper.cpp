#include <bits/stdc++.h>
#define INF ((int) 2e9)
using namespace std;

int main() {
    int n; scanf("%d", &n);
    map<int, int> mp;
    mp[-INF] = mp[INF] = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        auto it = mp.upper_bound(x);
        int p = prev(it)->second, q = it->second;
        int ans;
        if (p > q) {
            ans = prev(it)->first;
            mp[x] = p + 1;
        } else {
            ans = it->first;
            mp[x] = q + 1;
        }
        if (i > 1) printf("%d%c", ans, "\n "[i < n]);
    }
    return 0;
}
