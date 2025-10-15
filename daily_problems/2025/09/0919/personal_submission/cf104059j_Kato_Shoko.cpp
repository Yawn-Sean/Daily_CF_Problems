#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    string s;
    cin>>s;
    string op="cdhs";
    ll ans=0;
    do{
        vector<ll>dp(4);
        for(auto c:s){
            for(int i=0;i<4;i++){
                if(op[i]==c)dp[i]++;
            }
            dp[1]=max(dp[1],dp[0]);
            dp[2]=max(dp[2],dp[1]);
            dp[3]=max(dp[3],dp[2]);
        }
        ans=max(ans,dp[3]);
    }while(next_permutation(op.begin(),op.end()));
    cout<<s.size()-ans;
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
