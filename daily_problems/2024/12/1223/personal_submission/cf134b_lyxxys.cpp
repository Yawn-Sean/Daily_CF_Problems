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
    int n;
    cin >> n;

    auto gcds = [&](auto &&self, int a, int b)->int{
        if (b == 0){
            return -1;
        } else {
            return a/b + self(self, b, a%b);
        }
    };

    int res = 1e9;
    for (int i = 1; i <= n; ++ i){
        if (__gcd(i, n) == 1) fmin(res, gcds(gcds, i, n));
    }

    cout << res << "\n";
}
