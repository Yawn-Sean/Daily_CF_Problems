#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007; // 998244353

const int inv2 = (MOD + 1) / 2;
void solve(){
    string s;
    cin >> s;
    ll n;
    cin >> n;
    n %= MOD;
    int m = s.length();
    s = " " + s;
    vector<vector<ll>> pre(m + 1, vector<ll>(26, 0));
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < 26;j++){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][s[i] - 'a']++;
    }
    ll ans = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < s[i] - 'a';j++){
            ll t1 = (pre[m][j] - pre[i][j]) % MOD * n % MOD * (n + 1) % MOD * inv2 % MOD;
            ll t2 = (pre[i - 1][j]) * n % MOD * (n - 1) % MOD * inv2 % MOD;
            ans = (ans + t1) % MOD;
            ans = (ans + t2) % MOD;
        }
    }
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}