#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
 **/
struct DSU
{
    std::vector<int> f;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        f[y] = x;
        return true;
    }
};
void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<std::vector<int>> e(n);
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        v--;
        u--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (e[0].size() < d)
    {
        std::cout << "NO" << endl;
        return;
    }
    std::vector<std::pair<int, int>> ans;
    std::vector<int> vis(n);
    int cnt=1;
    vis[0]=-1;
    for(int i=1;i<n;i++){
        if(vis[i]==0){
            std::queue<int> q;
            q.push(i);
            vis[i]=cnt++;
            while(!q.empty()){
                auto u=q.front();
                q.pop();
                for(auto v:e[u]){
                    if(vis[v]==0){
                        vis[v]=vis[i];
                        q.push(v);
                    }
                }
            }
        }
    }
    std::vector<int> k;
    std::vector<int> flag(cnt);
    for(auto v:e[0]){
        if(flag[vis[v]]){
            continue;
        }
        else{
            flag[vis[v]]=1;
            k.push_back(v);
        }
    }
    if(k.size()>d){
        std::cout<<"NO"<<endl;
        return ;
    }
    std::queue<int> q;
    for (int i = 0; i < k.size(); i++)
    {
        ans.emplace_back(1, k[i] + 1);
        dsu.merge(0, k[i]);
        q.push(k[i]);
        d--;
    }
    int i = 0;
    while (d > 0)
    {
        if (dsu.merge(0, e[0][i]))
        {
            ans.emplace_back(1, e[0][i] + 1);
            d--;
            q.push(e[0][i]);
        }
        i++;
    }
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto v : e[u])
        {
            if (dsu.merge(v, u))
            {
                ans.emplace_back(u + 1, v + 1);
                // std::cout<<u+1<<" "<<v+1<<endl;
                q.push(v);
            }
        }
    }
    if (ans.size() != n - 1)
    {
        // std::cout<<ans.size()<<endl;
        std::cout << "NO" << endl;
    }
    else
    {
        std::cout << "YES" << endl;
        for (auto [u, v] : ans)
        {
            std::cout << u << " " << v << endl;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
}
