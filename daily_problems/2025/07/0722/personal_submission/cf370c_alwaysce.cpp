#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> color(n);
    vector<int> cnt(m + 1, 0);
    vector<vector<int>> idxs(m + 1);
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
        ++cnt[color[i]];
    }

    priority_queue<pair<int,int> > pq;
    for (int c = 1; c <= m; ++c) {
        if (cnt[c] > 0) {
            pq.push({cnt[c], c});
        }
    }

    int ans = 0;
    vector<pair<int,int>> res;
    while (pq.size() > 1) {
        auto [c1, i1] = pq.top(); pq.pop();
        if (c1 <= 1) { 
            pq.push({c1, i1});
            break;
        }
        auto [c2, i2] = pq.top(); pq.pop();
        c1--;
        c2--;

        res.emplace_back(i1, i2);
        res.emplace_back(i2, i1);
        if (c1 > 0) {
            pq.push({c1, i1});
        }
        if (c2 > 0) {
            pq.push({c2, i2});
        }
        ans += 2;
    }

    vector<int> left_colors;
    while (!pq.empty()) {
        auto [c, i] = pq.top(); pq.pop();
        for (int j = 0; j < c - 1; ++j) {
            res.emplace_back(i, i);
        }
        left_colors.push_back(i);
    }

    int x = left_colors.size();
    for (int i = 0; i < x; i++) {
        int from = left_colors[i];
        int to = left_colors[(i + 1) % x];
        res.emplace_back(from, to);
        if (from != to) {
            ans++;
        }
    }

    cout << ans << '\n';
    for (auto& [a, b] : res) {
        cout << a << ' ' << b << '\n';
    }
    
    return 0;
}
