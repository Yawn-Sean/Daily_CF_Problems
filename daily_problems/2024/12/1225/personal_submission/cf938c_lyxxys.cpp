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
    int tar;
    cin >> tar;
    for (i64 i = 1; i <= 200000; ++ i){
        if (i > 1 && i*i - (i/2)*(i/2) > tar) break;
        i64 lo = 1, hi = i;
        while (lo < hi){
            i64 mid = (lo+hi) >> 1;
            if (i*i-(i/mid)*(i/mid) >= tar) hi = mid;
            else lo = mid+1;
        }
        if (i*i-(i/lo)*(i/lo) == tar){
            cout << i << " " << lo << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;
}
