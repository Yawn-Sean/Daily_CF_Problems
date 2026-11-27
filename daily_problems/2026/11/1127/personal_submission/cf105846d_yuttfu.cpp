#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+1;
const int mod = 998244353;

ll res[N];
ll fac[N],inv[N];

ll qmi(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init(){
    fac[0] = inv[0] = 1;
    for(int i = 1;i < N;i++){
        fac[i] = fac[i-1] * i % mod;
    }
    inv[N-1] = qmi(fac[N-1],mod-2);
    for(int i = N - 2;i > 0;i--){
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    res[0] = 1;
    for(int i = 1;i < N;i++){
        if(i % 2 == 0) res[i] = (res[i-1] + inv[i]) % mod;
        else res[i] = ((res[i-1] - inv[i])%mod+mod)%mod;
    }
}

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << '\n';
        return;                                       
    }
    if(n % 2 == 0){
        cout << 1 << '\n';
        return;
    }
    cout << fac[n]*(fac[n]*res[n]%mod)%mod << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    init();
    while(T --){
        solve();
    }
    return 0;
}