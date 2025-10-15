#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
//题意很简单，一个简单的染色问题，数据范围也很小
//我们需要知道如何能在最小的情况下染完这些格子
//想象是在一棵树上，只要点之间有边就不能染成一样的
//如何去跑这个dfs或者bfs呢，我们可以从1点开始，对于所有没有边的点，我们都可以染成一个颜色
void sol()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n+1, vector<int>(n+1, 0));
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    vector<int> ans(n+1, 0);
    int now = 1;

    for (int i=1; i<=n; ++i) 
    {
        if (ans[i] == 0) 
        {
            queue<int> q;
            q.push(i);
            ans[i] = now;
            while (!q.empty()) 
            {
                int x = q.front();
                q.pop();
                for (int j=1; j<=n; ++j) 
                {
                    if (g[x][j] == 0 && ans[j] == 0) 
                    {
                        ans[j] = now;
                        q.push(j);
                    }
                }
            }
            now++;
        }
    }

    if (now-1 > k) 
    {
        cout << -1 << endl;
        return;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i != j && g[i][j] && ans[i] == ans[j]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
