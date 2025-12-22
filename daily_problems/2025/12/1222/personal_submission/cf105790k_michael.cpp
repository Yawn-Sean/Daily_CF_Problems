#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

struct Matrix{
    ll a[2][2];
};

Matrix base(){
    Matrix I;
    I.a[0][0] = 1,I.a[0][1] = 0;
    I.a[1][0] = 0,I.a[1][1] = 1;
    return I;
}

Matrix multiply(Matrix x,Matrix y){
    Matrix res;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            res.a[i][j] = 0;
        }
    }

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                res.a[i][j] += x.a[i][k] * y.a[k][j];
                res.a[i][j] %= (mod - 1);
            }
        }
    }
    return res;
}

Matrix matrix_pow(Matrix x,ll n){
    Matrix res;
    res = base();
    while(n){
        if(n & 1) res = multiply(res,x);
        x = multiply(x,x);
        n >>= 1;
    }
    return res;
}

ll quickPow(ll x,ll n){
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    Matrix fib;
    fib.a[0][0] = 1,fib.a[0][1] = 1;
    fib.a[1][0] = 1,fib.a[1][1] = 0;
    cout << quickPow(2ll,matrix_pow(fib,n).a[0][1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    cout << flush;
    return 0;
}