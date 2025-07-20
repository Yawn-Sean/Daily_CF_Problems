#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; scanf("%d", &n);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int h, l, r; scanf("%d%d%d", &h, &l, &r);
        mp[l].push_back(h); mp[r].push_back(-h);
    }

    vector<pii> ans;
    int last = 0;
    multiset<int> ms;
    for (auto &p : mp) {
        for (int x : p.second) {
            if (x > 0) ms.insert(x);
            else ms.erase(ms.find(-x));
        }
        int h = 0;
        if (ms.size() > 0) h = *prev(ms.end());
        if (h != last) {
            ans.push_back({p.first, last});
            ans.push_back({p.first, h});
            last = h;
        }
    }

    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
