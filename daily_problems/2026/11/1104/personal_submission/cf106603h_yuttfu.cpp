#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

ll qmi(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    if(n-2 <= 1){
        cout << 1 << '\n';
        return;
    }
    if((n-2)%3 == 1){
        cout << (qmi(3,(n-4)/3)*4) % mod << '\n';
    }else{
        ll ans = qmi(3,(n-2)/3);
        cout << (((n-2)%3) ? (ans*2%mod) : ans) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;

}