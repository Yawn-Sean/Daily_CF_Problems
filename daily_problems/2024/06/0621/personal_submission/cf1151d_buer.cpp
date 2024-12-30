#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
int mx;
int n,m,k;
PII a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n,[&](const auto&p,const auto&q){
       return -p.first+p.second<-q.first+q.second; 
    });
    int res=0;
    for(int i=1;i<=n;i++){
        res+=a[i].first*(i-1)+a[i].second*(n-i);
    }
    cout<<res;
} 
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
 
  //  cin>>t;
    while(t--) solve();
}
