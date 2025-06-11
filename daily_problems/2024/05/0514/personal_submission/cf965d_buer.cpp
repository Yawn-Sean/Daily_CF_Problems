#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
int s[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    auto check=[&](int x){
        for(int i=m;i<n;i++)
        {
            ///cout<<i<<" "<<i-m<<" "<<s[i]-s[i-m]<<"\n";
            if(s[i]-s[i-m]<x) return false;
        }  
        return true;
    };

    int l=0,r=1e18;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
