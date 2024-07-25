#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> graph(26, -1), indegs(26, 0), vis(26, -1);

    while (n --) {
        string s;
        cin >> s;
        int last = -1;
        for (auto &c: s) {
            int p = c - 'a';
            if (vis[p] == n) {
                cout << "NO";
                return 0;
            }
            vis[p] = n;
            if (last != -1) {
                if (graph[last] != -1 && graph[last] != p) {
                    cout << "NO";
                    return 0;
                }
                graph[last] = p;
            }
            last = p;
        }
    }


    int ma = 0;
    for (auto &x: graph)
        if (x >= 0) ma = max(ma, ++indegs[x]);
    
    if (ma > 1) {
        cout << "NO";
        return 0;
    }

    vector<int> ans;
    for (int idx = 0; idx < 26; idx ++) {
        if (indegs[idx] == 0 && vis[idx] >= 0) {
            int i = idx;
            vis[i] = -1;
            ans.emplace_back(i);
            while (graph[i] != -1)
                i = graph[i], vis[i] = -1, ans.emplace_back(i);
        }
    }

    for (int i = 0; i < 26; i ++)
        if (vis[i] >= 0) {
            cout << "NO";
            return 0;
        }
    
    for (auto &x: ans) cout << (char)('a' + x);

    return 0;
}