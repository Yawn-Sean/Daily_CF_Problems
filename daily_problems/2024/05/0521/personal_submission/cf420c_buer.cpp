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
int a[N];
void solve()
{

    cin>>n>>m;
    map<PII,int> mp;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        if(x>y) swap(x,y);
        a[x]++;a[y]++;
        mp[{x,y}]++;
    }
    int res=0;
    for(auto [k,v]:mp)
    {
        auto [x,y]=k;
        if(a[x]+a[y]>=m&&a[x]+a[y]-v<m)
        res--;
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid]+a[i]>=m) r=mid;
            else l=mid+1;
        }
        if(a[l]+a[i]<m) continue;
        res+=i-1-l+1;
    }
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
  //  cin>>t;
    while(t--) solve();
    return 0;
}
