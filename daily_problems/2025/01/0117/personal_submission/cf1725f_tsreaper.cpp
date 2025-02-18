#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 30
using namespace std;
typedef pair<int, int> pii;

int ans[MAXP + 1];
vector<pii> f[MAXP + 1];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r); l--; r--;
        for (int p = 0; p <= MAXP; p++) {
            if (r - l + 1 >= (1 << p)) {
                f[p].push_back({0, 1});
                f[p].push_back({1 << p, -1});
            }
            else {
                int ll = l % (1 << p), rr = r % (1 << p);
                if (ll <= rr) {
                    f[p].push_back({ll, 1});
                    f[p].push_back({rr + 1, -1});
                } else {
                    f[p].push_back({0, 1});
                    f[p].push_back({rr + 1, -1});
                    f[p].push_back({ll, 1});
                    f[p].push_back({1 << p, -1});
                }
            }
        }
    }
    for (int p = 0; p <= MAXP; p++) {
        sort(f[p].begin(), f[p].end());
        int now = 0;
        for (pii t : f[p]) {
            now += t.second;
            ans[p] = max(ans[p], now);
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        x = __lg(x & (-x));
        printf("%d\n", ans[x]);
    }
    return 0;
}
