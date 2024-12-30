#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, rt;
    cin >> n;

    vector<int> parent(n), cnt(n);
    vector<vector<int>> tree(n);

    for (int i = 0; i < n; i ++) {
        cin >> parent[i] >> cnt[i];
        parent[i] --;
        if (parent[i] >= 0)
            tree[parent[i]].push_back(i);
        else
            rt = i;
    }

    vector<int> ans(n);
    bool flg = true;

    function<vector<int>(int)> dfs = [&](int u) -> vector<int> {
        vector<int> nodes;
        for (auto &v: tree[u])
            for (auto &w: dfs(v))
                nodes.push_back(w);
        sort(nodes.begin(), nodes.end(), [&](int u, int v) {return ans[u] < ans[v];});
        if (nodes.size() < cnt[u]) flg = false;
        else {
            for (int i = 0; i < cnt[u]; i ++) ans[nodes[i]] = i + 1;
            ans[u] = cnt[u] + 1;
            for (int i = cnt[u]; i < nodes.size(); i ++) ans[nodes[i]] = i + 2;
            nodes.push_back(u);
        }
        return nodes;
    };

    dfs(rt);

    if (flg) {
        cout << "YES\n";
        for (auto &x: ans)
            cout << x << ' ';
    }
    else
        cout << "NO";
    return 0;
}