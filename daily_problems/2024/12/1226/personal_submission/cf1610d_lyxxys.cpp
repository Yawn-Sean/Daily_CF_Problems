#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+7;    
    auto pows = [&](i64 a, int b)->int{
        i64 res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };
    auto w = [&](int x)->int{
        return 31 - __builtin_clz(x&-x);
    };

    int n;
    cin >> n;
    vector <int> cnt(31);
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        cnt[w(x)] += 1;
    }
    i64 res = 0, lst = 0;
    for (int i = 30; i >= 1; -- i){
        if (cnt[i] > 1){
            (res += 1ll * (pows(2, cnt[i]-1)-1) * pows(2, lst) % mod) %= mod;
            if (res < 0) res += mod;
        }
        lst += cnt[i];
    }
    (res += 1ll * (pows(2, cnt[0])-1) * pows(2, lst) % mod) %= mod;
    if (res < 0) res += mod;
    cout << res << "\n";
}
