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
PII a[N];
vector<int> g[N];
void solve()
{
    cin>>n>>m;
    int res=inf;
    for(int i=1;i<=n;i++)
    cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++) g[a[i].first].push_back(a[i].second);
    for(int i=1;i<=m;i++) sort(g[i].begin(),g[i].end());
    for(int i=max(1ll,(int)g[1].size());i<=n;i++)
    {
        int now=g[1].size(),tot=0;
        for(int j=2;j<=m;j++)
        {
            if(g[j].size()<i)continue;
            int need=(int)g[j].size()-(i-1);
            for(int k=0;k<need;k++)
            {
                tot+=g[j][k];
                now++;
            }
        }    
        if(now>=i){
            res=min(res,tot);continue;
        }
        priority_queue<PII> q;
        for(int j=2;j<=m;j++){
            if(g[j].size()>=i){
                int need=(int)g[j].size()-(i-1);
                for(int k=need;k<g[j].size();k++)
                {
                    int x=g[j][k];
                    tot+=x;
                    q.emplace(x,j);
                    if(q.size()>i-now){
                        tot-=q.top().first;
                        q.pop();
                    }
                }
            }
            else{
                for(auto x:g[j])
                {
                    tot+=x;
                    q.emplace(x,j);
                    if(q.size()>i-now){
                        tot-=q.top().first;
                        q.pop();
                    }
                }
            }
        }
        res=min(res,tot);
    }
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   
    //cin>>t;
    while(t--) solve();
    return 0;
}
