#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e6+3;
int ksm(int a,int b,int res=1){
    while(b){
        if(b%2)res=res*a%mod;
        b/=2;a=a*a%mod;
    }
    return res;
}
void solve(){
    int n,c;cin>>n>>c;
    vector<int>fac(n+c+1,1),inv(n+c+1,1);
    for(int i=1;i<=n+c;i++)fac[i]=fac[i-1]*i%mod;
    inv[n+c]=ksm(fac[n+c],mod-2);
    for(int i=n+c-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    auto C=[&](int a,int b)->int{
        if(a<0||b>a)return 0;
        return fac[a]*inv[a-b]%mod*inv[b]%mod;
    };
    int res=0;
    for(int i=1;i<=n;i++){
        // cout<<i+c<<' '<<c-1<<' '<<C(i+c-1,c-1)<<'\n';
        res=(res+C(i+c-1,c-1))%mod;
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}