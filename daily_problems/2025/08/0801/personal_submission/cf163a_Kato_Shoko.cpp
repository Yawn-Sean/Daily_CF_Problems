#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 1e9+7, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s="!"+s,t="~"+t;
    //选择一个以s[i]结尾的子串与一个以 t[j]结尾的子序列，它们内容相同的方案数。
    vector<vector<ll>>dp(n+5,vector<ll>(m+5));
    ll ans=0;
    vector<ll>pre(m+1);
    for(int i=1;i<=n;i++){
        pre[0]=0;
        for(int j=1;j<=m;j++){
            pre[j]=(pre[j-1]+dp[i-1][j])%mod;
        }
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                dp[i][j]=(1+pre[j-1])%mod;
                ans=(ans+dp[i][j])%mod;
            }
        }
    }
    cout<<ans;
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
