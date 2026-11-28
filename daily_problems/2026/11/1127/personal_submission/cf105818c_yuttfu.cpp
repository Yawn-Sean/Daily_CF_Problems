#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int N = 1e6+1;

ll qmi(ll a,ll b){
    ll res = 1;
    a %= b;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll fac[N],inv[N];

void init(){
    fac[0] = inv[0] = 1;
    for(int i = 1;i < N;i++){
        fac[i] = fac[i-1] * i % mod;
    }
    inv[N-1] = qmi(fac[N-1],mod-2);
    for(int i = N-2;i > 0;i--){
        inv[i] = inv[i+1] * (i+1) % mod;
    }
}

ll C(int a,int b){
    if(a < b || b < 0) return 0;
    return (fac[a]*inv[b]%mod)*inv[a-b]%mod;
}

void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((a+d)-(b+c) != 0 && (a+d)-(b+c) != 1){
        cout << 0 << '\n';
        return;
    }
    ll ans = C(a+d-2,d) * C(b+c,b) % mod;
    cout << ans << '\n';
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

