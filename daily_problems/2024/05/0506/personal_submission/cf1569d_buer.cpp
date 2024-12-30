#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N],b[N];
int cnt[N],to[N];
int num[N],q[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    memset(to,0x3f,sizeof(to));
   /// vector<vector<int>> f(n+10,vector<int>(n,0));
    for(int i=1;i<=m;i++)
    {
        cnt[a[i]]++;
        to[a[i]]=min(to[a[i]],(b[i]-a[i]+n)%n);    
    }
    for(int i=0;i<n;i++){
        if(cnt[i])
        num[i]=i+(cnt[i]-1)*n+to[i];
    }
    for(int i=n;i<2*n;i++)
        if(num[i-n])
        num[i]=num[i-n]+n;
    int hh=0,tt=-1;
    for(int i=0;i<n;i++){
        while(hh<=tt&&num[q[tt]]<=num[i])
        tt--;
        q[++tt]=i;
    }
    
    for(int i=0;i<n;i++){
        while(hh<=tt&&q[hh]<i) hh++;
        cout<<num[q[hh]]-i<<" ";
        while(hh<=tt&&num[q[tt]]<=num[i+n])
        tt--;
        q[++tt]=i+n;
    }
    //vector<int> res(n+10);
    
    
    //最后一个能拿的糖果肯定是固定的
    //
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
