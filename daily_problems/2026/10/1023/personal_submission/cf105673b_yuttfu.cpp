#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 2e5+10;
ll a[N];

void solve(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll ans = k;
    int m = (sqrt(8*n-7)+1)/2;
    vector<vector<ll>> dp(2,vector<ll>(n+1,0));
    for(int i = 1;i <= n;i++){
        dp[0][i] = a[i] + k;
        ans = max(ans,dp[0][i]);
    }
    int id = 0;
    for(int i = 2;i <= m;i++){
        int j = i*(i-1)/2 + 1;
        for(;j <= n;j++){
            if(dp[id][j-i+1] >= 0) dp[1-id][j] = dp[id][j-i+1] + a[j];
            else dp[1-id][j] = -1;
            ans = max(ans,dp[1-id][j]);
        }
        id = 1-id;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}