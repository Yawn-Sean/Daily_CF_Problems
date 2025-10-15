#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,kr,kg,kb;
    cin>>n>>kr>>kg>>kb;
    vector<ll>R(n+1),G(n+1),B(n+1);
    vector<ll>notR(n+1),notG(n+1),notB(n+1);
    vector<ll>perR(n+1),perG(n+1),perB(n+1);//notRGB的前缀和
    
    notR[0]=notG[0]=notB[0]=perR[0]=perG[0]=perB[0]=1;

    for(int i=1;i<=n;i++){
        ll l=max(0ll,i-kr);
        ll r=i-1;
        ll sum=perR[r];
        if(l-1>=0){
            sum=(sum-perR[l-1]+mod)%mod;
        }
        R[i]=sum;

        l=max(0ll,i-kg);
        sum=perG[r];
        if(l-1>=0){
            sum=(sum-perG[l-1]+mod)%mod;
        }
        G[i]=sum;

        l=max(0ll,i-kb);
        sum=perB[r];
        if(l-1>=0){
            sum=(sum-perB[l-1]+mod)%mod;
        }
        B[i]=sum;

        notR[i]=(G[i]+B[i])%mod;
        notG[i]=(R[i]+B[i])%mod;
        notB[i]=(R[i]+G[i])%mod;

        perR[i]=(perR[i-1]+notR[i])%mod;
        perG[i]=(perG[i-1]+notG[i])%mod;
        perB[i]=(perB[i-1]+notB[i])%mod;
    }

    cout<<((R[n]+G[n])%mod+B[n])%mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
