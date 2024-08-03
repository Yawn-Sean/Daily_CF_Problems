#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <climits>

using namespace std;
using i64 = long long;
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    
    vector<int> vis(n + 1), bid[n + 1];
    set<pair<int, int>> maxv;

    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        bid[a].push_back(b);
        vis[a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            maxv.insert({bid[i].back(), i});
        }
    }
    int q, k, c;
    cin >> q;
    while (q--) {
        cin >> k;
        vector<int> leave;
        for (int i = 0; i < k; i++) {
            cin >> c;
            if (vis[c]) {
                leave.push_back(c);
                maxv.erase({bid[c].back(), c});
            }
        }
        if (maxv.size() == 0) {
            cout << "0 0\n";
        } else if (maxv.size() == 1) {
            cout << maxv.begin()->second << ' ' << bid[maxv.begin()->second][0] << '\n';
        } else {
            auto it1 = prev(maxv.end());
            auto it2 = prev(it1);
            int p2 = it2->second, p1 = it1->second;
            auto cost = *lower_bound(bid[p1].begin(), bid[p1].end(), it2->first);
            cout << p1 << ' ' << cost << '\n';
        }
        for (auto x : leave) {
            maxv.insert({bid[x].back(), x});
        }
    }
}

int main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}