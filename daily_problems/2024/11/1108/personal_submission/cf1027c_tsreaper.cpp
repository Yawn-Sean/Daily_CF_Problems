#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }
    for (auto &p : mp) if (p.second >= 4) {
        for (int i = 0; i < 4; i++) printf("%d%c", p.first, "\n "[i < 3]);
        return;
    }

    int x = 0, y = 0;
    long double best = 1e300;
    int last = 0;
    for (auto &p : mp) if (p.second >= 2) {
        if (last == 0) { last = p.first; continue; }
        long double t = 2 * (last + p.first);
        t = t * t / (last * p.first);
        if (t < best) x = last, y = p.first, best = t;
        last = p.first;
    }
    printf("%d %d %d %d\n", x, x, y, y);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
