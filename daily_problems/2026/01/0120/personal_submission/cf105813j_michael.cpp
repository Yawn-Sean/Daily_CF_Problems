#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int N = 2e5;
int f[N + 1],g[N + 1];

ll quickPow(ll a, ll b,int mod){
    ll ans = 1;
    while(b != 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

void solve(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ans = (ans + x) % mod;
    }
    cout << 1ll * ans * f[n - 1] % mod * g[n] % mod << '\n'; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    f[0] = 1;
    for(int i = 1; i <= N; ++i){
        f[i] = 1ll * i * f[i - 1] % mod;
    }
    g[N] = quickPow(f[N],mod - 2,mod);
    for(int i = N; i > 0; --i){
        g[i - 1] = 1ll * g[i] * i % mod;
    }
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}