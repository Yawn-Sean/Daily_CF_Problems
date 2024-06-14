#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18, mod = 998244353, N = 20050;
ll f[N][200];

void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    vector <ll> a(n+1), Pre(n+1);
    //组合dp，f[i][j] 第i个位置分成第j段的最大值
    for (int i = 1; i <= n; ++ i) cin >> a[i], Pre[i] = a[i] + Pre[i-1];

    for (int i = 1; i <= n; ++ i){
        f[i][1] = Pre[i]%p;
        for (int j = 2; j <= k; ++ j){
            for (int t = i-1; t >= 1; -- t) {
                if (f[t][j-1]+p-1 <= f[i][j]) break;
                f[i][j] = max(f[i][j], f[t][j - 1] + (Pre[i] - Pre[t]) % p);
            }
        }
    }

    cout << f[n][k] << "\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
