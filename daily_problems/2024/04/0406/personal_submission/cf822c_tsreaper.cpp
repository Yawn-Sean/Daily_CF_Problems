#include <bits/stdc++.h>
#define INF ((int) 2e9 + 7)
using namespace std;
typedef pair<int, int> pii;

int main() {
    map<int, vector<pii>> mp;
    unordered_map<int, multiset<int>> seg;
    int n, K; scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int l, r, v; scanf("%d%d%d", &l, &r, &v);
        int len = r - l + 1;
        mp[l].push_back(pii(len, -v));
        mp[r].push_back(pii(len, v));
        seg[len].insert(v);
    }
    int ans = INF;
    for (auto &p : mp) {
        for (auto &q : p.second) if (q.second < 0) seg[q.first].erase(seg[q.first].find(-q.second));
        for (auto &q : p.second) if (q.second >= 0) {
            int goal = K - q.first;
            if (seg.count(goal) && seg[goal].size() > 0) ans = min(ans, q.second + *(seg[goal].begin()));
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
