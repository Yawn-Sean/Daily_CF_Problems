#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int sz[N];
vector<int> g[N];
void dfs(int u,int fa){
    bool f=true;
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        f=false;
        sz[u]+=sz[v];
    }
    sz[u]+=f;
}
void solve()
{
   cin>>n;
   for(int i=2;i<=n;i++){
       int a,b;cin>>a;
       g[a].push_back(i);
       g[i].push_back(a);
   }
   dfs(1,0);
   sort(sz+1,sz+1+n);
   for(int i=1;i<=n;i++){
       cout<<sz[i]<<" \n"[i==n];
   }
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
