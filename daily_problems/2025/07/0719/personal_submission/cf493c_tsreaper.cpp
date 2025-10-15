#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    map<int, pii> mp;

    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x].first++;
    }

    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        mp[x].second++;
    }

    int ans1 = 3 * n, ans2 = 3 * m;
    int cnt1 = 0, cnt2 = 0;
    for (auto &p : mp) {
        cnt1 += p.second.first; cnt2 += p.second.second;
        int t1 = 2 * cnt1 + 3 * (n - cnt1);
        int t2 = 2 * cnt2 + 3 * (m - cnt2);
        if (t1 - t2 > ans1 - ans2) ans1 = t1, ans2 = t2;
        if (t1 - t2 == ans1 - ans2 && t1 > ans1) ans1 = t1, ans2 = t2;
    }
    printf("%d:%d\n", ans1, ans2);
    return 0;
}
