#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 7010;
int n, st[N][N], a[N];
ll dp[N][N], pre[N][N];
const int mod = 998244353;
void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i < n; ++i){
        int R = i + 1;
        for (int j = 1; j < i; ++j){
            while(R <= n && a[i] + a[j] > a[R]){
                R++;
            }
            if (R <= n) {
                st[R][i] = j;
            }else{
                break;
            }
        }
    }
    for (int j = 1; j <= n; ++j){
        for (int i = j + 1; i <= n; ++i){
            st[i][j] = max(st[i][j], st[i - 1][j]);
        }
    }
    
    for (int i = 2; i <= n; ++i){
        for(int j = 1; j <= i - 1; ++j){
            int fr = st[i][j];
            if (fr == 0){

            }else{
                dp[i][j] = (fr + pre[j][fr]) % mod;
            }
            pre[i][j] = (dp[i][j] + pre[i][j - 1]) % mod;
        }
        pre[i][i] = pre[i][i - 1];
    }
    ll ans = 0;
    for (int i = 3; i <= n; ++i){
        ans = (ans + pre[i][i]) % mod;
    }
    ans = (ans + n + 1LL * n * (n - 1) / 2) % mod;
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}