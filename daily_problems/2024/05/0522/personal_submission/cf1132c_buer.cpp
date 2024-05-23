#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=998244353;

#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
int x[N],y[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>x[i]>>y[i];
    int res=0;
    for(int i=1;i<=m;i++){
        vector<int> d(n+10);
        for(int j=1;j<=m;j++){
            if(j==i) continue;
            d[x[j]]++;
            d[y[j]+1]--;           
        }
        vector<int> sum(n+10);
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            d[j]+=d[j-1];
            if(d[j]>=2) sum[j]++;
            sum[j]+=sum[j-1];
            if(d[j]) cnt++;
        }
        for(int j=1;j<=m;j++){
            if(j==i) continue;
            res=max(res,cnt-(y[j]-x[j]+1-(sum[y[j]]-sum[x[j]-1])));
        }
    }
    cout<<res<<"\n";
}   

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
