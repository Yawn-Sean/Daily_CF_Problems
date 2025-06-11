#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){  
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+9;
    auto pows = [&](long long a, int b)->int{
        long long res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };

    int n, m, k;
    cin >> n >> m >> k;

    int score = (n/k)*(k-1) + n%k;
    if (m <= score){
        cout << m << "\n";
    } else {
        int r = m - score;
        assert(r <= n/k);
        assert(m >= k*r);

        long long res = m - k*r;
        int x = 1ll*4*k * pows(2, r-1) % mod;
        int y = 2*k % mod;
        x -= y;
        if (x < 0) x += mod;
        res = (res + x) % mod;

        cout << res << "\n";
    }
}
