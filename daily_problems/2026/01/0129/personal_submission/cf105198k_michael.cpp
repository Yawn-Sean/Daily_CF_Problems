#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int N = 2e6;
int fac[N + 1],inv[N + 1];

ll quickPow(ll a,int n){
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

ll comb(int x,int y){
    return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

void solve(){
    int b,g,x,y;
    cin >> b >> g >> x >> y;
    if(x + y > g){
        cout << 0 << '\n';
    }else{
        int ans = 0;
        ans = (ans + comb(b + g,g)) % mod;
        ans = (ans + mod - comb(b + x + y - 1,b)) % mod;
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    fac[0] = 1;
    for(int i = 1; i <= N; ++i){
        fac[i] = 1ll * i * fac[i - 1] % mod;
    }
    inv[N] = quickPow(1ll * fac[N],mod - 2);
    for(int i = N - 1; i >= 0; --i){
        inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
    }
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}