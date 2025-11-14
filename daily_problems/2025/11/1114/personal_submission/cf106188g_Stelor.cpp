#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 101;
int n, k, a[N];
ll dp[N][10005];
const int mod = 1E9 + 7;

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }   
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        // 第i个作为最大值
        for (int j = a[i] + 1; j <= a[n] + 1; ++j){
            ans = (ans + dp[k - 1][j]) % mod;
        }
        for (int j = k - 2; j >= 0; --j){
            for (int p = 0; p <= a[n] + 1; ++p){

                dp[j + 1][min(p + a[i], a[n] + 1)] = (dp[j][p] + dp[j + 1][min(p + a[i], a[n] + 1)]) % mod;           
            }
        }
    } 
    cout << ans;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}