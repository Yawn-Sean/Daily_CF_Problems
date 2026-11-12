#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    vector<int> dp(65,0);
    int ans = 1;
    for(int i = 1;i <= n;i++){
        if(a[i] == 0) continue;
        int len = 1;
        ll h = 63 - __builtin_clzll(a[i]);
        for(int k = 0;k < h;k++){
            if((a[i]>>k) & 1ll){
                len = max(len,dp[k]+1);
            }
        }
        dp[h] = max(dp[h],len);
        ans = max(ans,dp[h]);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
