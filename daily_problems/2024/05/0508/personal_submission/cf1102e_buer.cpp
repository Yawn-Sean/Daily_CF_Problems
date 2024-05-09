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
int a[N],b[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int r=0;
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[a[i]]=i;
    int res=1;
    r=mp[a[1]];
    for(int i=2;i<=n;i++)
    {
        if(r<i) res=res*2%mod;
        r=max(r,mp[a[i]]);
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
