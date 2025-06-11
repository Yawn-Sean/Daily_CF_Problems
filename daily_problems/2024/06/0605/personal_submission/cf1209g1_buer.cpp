#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
int r[N],cnt[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r[a[i]]=i;
        cnt[a[i]]++;
    }
    int i=1,ans=0;
    while(i<=n){
        int mxr=i,mxs=0;
        while(i<=mxr){
            mxs=max(mxs,cnt[a[i]]);
            mxr=max(mxr,r[a[i]]);
            i++;
        }
        ans+=mxs;
    }
    cout<<n-ans<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}
