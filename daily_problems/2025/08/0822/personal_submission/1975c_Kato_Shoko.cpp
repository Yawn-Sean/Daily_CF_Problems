#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

ll dp[N];

il void solve(){
    int n,k;
    cin>>n>>k;
    while(k--){
        int x,y;
        cin>>x>>y;
        if(x==y)n--;
        else n-=2;
    }
    cout<<dp[n]<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    dp[0]=dp[1]=1;
    for(ll i=2;i<=3e5;i++){
        dp[i]=(2*(i-1)%mod*dp[i-2]%mod+dp[i-1])%mod;
    }

    while (t--) {

        solve();

    }

    return 0;
}
