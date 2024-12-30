#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ends(n), nex(n, -1), head(n, -1);
    iota(ends.begin(), ends.end(), 0);

    function<int(int)> find_head = [&] (int u) -> int {
        int p = u;
        while (head[p] >= 0) p = head[p];
        while (u != p) {
            int nu = head[u];
            head[u] = p;
            u = nu;
        }
        return p;
    };

    function<void(int, int)> merge_link = [&] (int u, int v) {
        u = find_head(u);
        v = find_head(v);
        if (head[u] > head[v]) swap(u, v);
        head[u] += head[v];
        head[v] = u;
        nex[ends[u]] = v;
        ends[u] = ends[v];
    };

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        merge_link(u, v);
    }

    int rt = find_head(0);
    for (int i = 0; i < n; i ++)
        cout << rt + 1 << ' ', rt = nex[rt];

    return 0;
}