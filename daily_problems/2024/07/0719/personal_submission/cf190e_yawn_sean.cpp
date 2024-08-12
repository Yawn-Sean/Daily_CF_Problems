#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nodes, last_idx, path(n, -1);

    function<void(int, int)> add_edge = [&] (int u, int v) {
        last_idx.push_back(path[u]);
        path[u] = nodes.size();
        nodes.emplace_back(v);
    };

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        add_edge(u, v);
        add_edge(v, u);
    }

    unordered_set<int> st;
    for (int i = 0; i < n; i ++)
        st.emplace(i);

    vector<vector<int>> ans;
    
    while (!st.empty()) {
        int u = *st.begin();
        st.erase(u);

        vector<int> stk = {u}, cur;
        while (stk.size()) {
            u = stk[stk.size() - 1];
            stk.pop_back();
            cur.push_back(u);

            unordered_set<int> new_st;
            int cur = path[u];
            while (cur >= 0) {
                if (st.find(nodes[cur]) != st.end()) {
                    st.erase(nodes[cur]);
                    new_st.emplace(nodes[cur]);
                }
                cur = last_idx[cur];
            }
            swap(st, new_st);
            for (auto &x: new_st)
                stk.push_back(x);
        }
        ans.push_back(cur);
    }
    cout << ans.size() << '\n';
    for (auto &cur: ans) {
        cout << cur.size() << ' ';
        for (auto &x: cur) cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}