#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<uLL,int,int>;
int n,m,k;
int a[N],b[N];

void solve()
{
   cin>>n>>k;
   for(int i=1;i<=n;i++) cin>>a[i];
   map<int,int> mp;
   //for(int i=1;i<=n;i++) mp[a[i]]++;
   cin>>m;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=k;j++){
           if(mp.count(j*a[i])) mp[j*a[i]]=min(mp[j*a[i]],j);
           else mp[j*a[i]]=j;
       }
   }
   while(m--)
   {
       int res=inf;
        int x;cin>>x;
        for(int i=1;i<=n;i++){
            if(x%a[i]==0) res=min(res,x/a[i]);
            for(int j=1;j<=k;j++){
                if(x<j*a[i]) break;
                if(mp.count(x-j*a[i])) res=min(res,j+mp[x-j*a[i]]);
            }
        }
        if(res>k) res=-1;
        cout<<res<<"\n";
   }
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
 //   init();
    //cin>>t;
    while(t--) solve();
    return 0;
}
