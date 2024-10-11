#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 2e+5;
const ll mod=1e9+7;
void clear(queue<int> &q){
    queue<int> empty;
    swap(empty,q);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,s,t,u,v;
    cin>>n>>m>>s>>t;
    vector<vector<int>> g(n+1,vector<int>());
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist_s(n+1,inf),dist_t(n+1,inf);
    queue<int> q;
    q.push(s);
    int temps=0;
    bool vis[n+1];
    fill(vis, vis + n + 1, false);
    vis[s]=true;
    while(!empty(q)){
        int size_q=q.size();
        for(int i=0;i<size_q;i++){
            int cur=q.front();
            dist_s[cur]=temps;
            q.pop();
            for(auto x:g[cur]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        temps++;
    }
    clear(q);
    q.push(t);
    temps=0;
    fill(vis, vis + n + 1, false);
    vis[t]=true;
    while(!empty(q)){
        int size_q=q.size();
        for(int i=0;i<size_q;i++){
            int cur=q.front();
            dist_t[cur]=temps;
            q.pop();
            for(auto x:g[cur]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        temps++;
    }
    int d=dist_s[t],ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i!=j&&
            find(g[i].begin(), g[i].end(),j)==g[i].end()&&
            (dist_s[i]+dist_t[j]+1>=d&&dist_s[j]+dist_t[i]+1>=d)){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
