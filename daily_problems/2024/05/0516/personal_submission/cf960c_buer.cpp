#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
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
    int x,d;
   cin>>x>>d;
   vector<int> res;
   int now=1;
   for(int i=31;i>=0;i--)
   {
       if(x>>i&1){
            for(int j=0;j<i;j++)
            {
                res.push_back(now);
            }
            now+=d;
            res.push_back(now);
            now+=d;
       }
   }
    cout<<res.size()<<"\n";
    for(auto x:res) cout<<x<<" ";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

    //cin>>t;
    while(t--) solve();
    return 0;
}
