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
    i64 p, q;
    cin >> p >> q;
    if (q == 0){
        cout << fixed << setprecision(10) << 1.0 << "\n";
        return;
    }
    if (p == 0){
        cout << fixed << setprecision(10) << 0.5 << "\n";
        return;
    }
    long double res;
    i64 all = 8*p*q;
    if (p <= 4*q){
        res = 1.0*(8*p*q + p*p)/(2*all);
    } else {
        res = 1.0*(4*p*q + 4*q*(p-2*q))/all;
        // 梯形 (p-4q+p)/2 * 4q
    }
    cout << fixed << setprecision(10) << res << "\n";
}

