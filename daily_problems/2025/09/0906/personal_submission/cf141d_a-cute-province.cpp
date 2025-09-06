#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10; 
const int mod = 1e9 + 7;
void solve()
{
    int n, L;
    cin >> n >> L;
    vector<int> x(n), d(n), t(n), p(n), arr;  
    arr.emplace_back(0), arr.emplace_back(L);
    for(int i = 0 ;i < n; i++){
        cin >> x[i] >> d[i] >> t[i] >> p[i];
        if(x[i]-p[i] >= 0)arr.emplace_back(x[i]-p[i]), arr.emplace_back(x[i] + d[i]);
    }
    if(n == 0){
        cout << L << '\n';
        cout << 0 << '\n';
        return ;
    }
    std::vector<int> tmp(arr);  // tmp 是 arr 的一个副本
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    map<int, int> id;
    for(int i = 0; i < tmp.size(); i ++)id[tmp[i]] = i;
    int m = tmp.size();
    vector<vector<array<int, 3>>> g(m);
    for(int i = 0 ;i < n; i ++){
        if(x[i]-p[i] >= 0)g[id[x[i]-p[i]]].push_back({id[x[i] + d[i]], t[i] + p[i], i});
    }
    for(int i = 0 ;i < m- 1; i ++){
        g[i].push_back({i+1, tmp[i+1]-tmp[i], -1});
        g[i+1].push_back({i, tmp[i+1]-tmp[i], -1});
    }
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> vis(m), dis(m, 1e9);
    vector<PII> path(m);
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto ve : g[u]){
            int v = ve[0], w = ve[1], id = ve[2];
            if(dis[u] + w < dis[v]){
                path[v] = {u, id};
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    cout << dis[m-1] << '\n';
    vector<int> ans;
    int st = m-1;
    while(st != 0){
        auto [x, y] = path[st];
        if(y != -1)ans.emplace_back(y);
        st = x;
    }
    cout << ans.size() <<'\n';
    for(int i = (int)ans.size()-1; i >= 0; i --)cout << ans[i] +1 << ' ';
    cout << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
    //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
