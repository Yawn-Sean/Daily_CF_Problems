#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


#define all(a) a.begin(), a.end()
#define endc endl; return
#define i128 __int128_t

typedef long long ll;

bool mult_test = false;
const char ln = '\n';
const int mod1 = 998244353, mod2 = 1e9 + 7, N = 1e6 + 7, inf = 2147483647 - 1;
const int mv[5] = {-1, 0, 1, 0, -1};

ll fp(ll x, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * x) % mod2;
        x = x * x % mod2;
        n >>= 1;
    }
    return res;
}


void INIT(){ 
    mult_test = true;
}
void solve(){
    ll n;
    cin >> n;
    cout << ((n - 3 + mod2) % mod2 * fp(2, n) % mod2 + n + 3) % mod2 << ln;
}     
int main(){ 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    INIT();
    int T = 1;
    if(mult_test) cin >> T; 
    while(T --> 0) solve();
}
