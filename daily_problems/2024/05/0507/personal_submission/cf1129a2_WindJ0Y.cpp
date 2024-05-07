#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n, {0, 1e9});
    while (m --) {
        int s, t; cin >> s >> t;
        s --; t --;
        if (t < s) { t += n; }
        a[s].first ++;
        a[s].second = min(a[s].second, t);
    }

    for (int sp = 0; sp < n; sp ++) {
        int tans = 0;
        for (auto pcnt = 0; pcnt < n; pcnt ++) {
            int pid = (sp + pcnt) % n;
            auto [tcnt, mintv] = a[pid];
            int pv = tcnt ? ((tcnt - 1) * n + (mintv - pid) + pcnt) : 0;
            tans = max(tans, pv);
        }
        cout << tans << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}