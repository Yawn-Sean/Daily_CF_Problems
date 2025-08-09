#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> rows(n), cols(n);
    map<int, vector<pair<int,int>>> diagonal1, diagonal2;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        rows[x - 1].emplace_back(y - 1, i);
        cols[y - 1].emplace_back(x - 1, i);
        diagonal1[x - y].emplace_back(x - 1, i);
        diagonal2[x + y].emplace_back(x - 1, i);
    }


    vector<int> cnt(m);
    auto get_cnt = [&](vector<pair<int,int>>& v) {
        sort(v.begin(), v.end());
        int x = v.size();
        if (x < 2) {
            return;
        }
        for (int i = 0; i < x; i++) {
            if (i == 0 || i == x - 1) {
                ++cnt[v[i].second];
            } else {
                cnt[v[i].second] += 2;
            }
        }
    };

    for (auto& row: rows) {
        get_cnt(row);
    }
    for (auto& col: cols) {
        get_cnt(col);
    }
    for (auto& [_, v] : diagonal1) {
        get_cnt(v);
    }
    for (auto& [_, v] : diagonal2) {
        get_cnt(v);
    }

    vector<int> ans(9);
    for (int i = 0; i < m; i++) {
        ans[cnt[i]]++;
    }
    for (int i = 0; i < 9; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
