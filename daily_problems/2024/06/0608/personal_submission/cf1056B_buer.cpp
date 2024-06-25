#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<uLL,int,int>;
int n,m,k;
PII a[N],b[N];
int s[N];
int pre[N];
void solve()
{
    cin>>n>>m;
    vector<int> cnt(m+10);
    for(int i=1;i<=m;i++) 
    cnt[i*i%m]+=n/m;
    for(int i=n/m*m+1;i<=n;i++)
    cnt[i*i%m]++;
    int res=0;
    for(int i=0;i<m;i++){
        res+=cnt[i]*cnt[(m-i)%m];
    }
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
 //   init();
   // cin>>t;
    while(t--) solve();
    return 0;
}
