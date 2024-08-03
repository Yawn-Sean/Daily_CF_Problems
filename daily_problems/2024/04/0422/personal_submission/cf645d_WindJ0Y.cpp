#include <bits/stdc++.h>
using namespace std;

int bit_wize_f_sum(int v) {
    switch (v % 4) {
        case 0: return v;
        case 1: return 1;
        case 2: return v + 1;
        case 3: return 0;
    }
}
void work() {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> edgs(m);
    for (int i = 0; i < m; i++) {
        cin >> edgs[i].first >> edgs[i].second;
        edgs[i].first --;
        edgs[i].second --;
    }

    int vtop = bit_wize_f_sum(n - 1);
    int top_cnt = n; // cnt(in[i] == 0)

    vector<int> in(n);
    vector<vector<int>> nxts(n);

    vector<int> has_pop(n);
    int pop_cnt = 0;

    int edge_pos = 0;
    auto add_edge = [&]() {
        if (edge_pos >= m) {
            cout << -1 << "\n";
            exit(0);
            return false;
        }
        auto [s, t] = edgs[edge_pos];
        edge_pos ++;
        if (has_pop[s]) {
            // skip
        } else {
            if (in[t] == 0) {
                vtop ^= t;
                top_cnt --;
            }   
            in[t]++;
            nxts[s].push_back(t);
        }
        return true;
    };

    while (pop_cnt < n) {
        while (top_cnt > 1) add_edge();

        int to_remove = vtop;

        vtop ^= to_remove; // 0
        top_cnt --; // 0
        pop_cnt ++;
        has_pop[to_remove] = 1;

        for (auto nxt : nxts[to_remove]) {
            in[nxt] --;
            if (in[nxt] == 0) {
                vtop ^= nxt;
                top_cnt ++;
            }
        }
    }

    cout << edge_pos << "\n";
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