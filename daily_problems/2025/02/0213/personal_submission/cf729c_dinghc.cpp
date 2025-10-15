#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 2e9;

int main() {
    int n, k, s, t;
    scanf("%d%d%d%d", &n, &k, &s, &t);
    vector<pair<int, int>> cs(n);
    for (auto& [c, v] : cs) {
        scanf("%d%d", &c, &v);
    }
    vector<int> gs(k);
    for (auto& p : gs) {
        scanf("%d", &p);
    }
    gs.push_back(s);
    ranges::sort(gs);
    auto check = [&] (int w) -> bool {
        int curr = 0;
        int pre = 0;
        for (int i = 0; i <= k; i++) {
            int x = gs[i] - pre;
            if (w < x) return false;
            // a + b = x, 2 * a + b = w
            int f = min(w - x, x);
            curr += f + 2 * (x - f);
            pre = gs[i];
        }
        return curr <= t;
    };
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (check(md)) {
            hi = md - 1;
        } else {
            lo = md + 1;
        }
    }
    int ans = inf;
    for (auto&[c,v] : cs) {
        if (v >= lo) {
            ans = min(ans, c);
        }
    }
    printf("%d\n", ans < inf ? ans : -1);
    return 0;
}

