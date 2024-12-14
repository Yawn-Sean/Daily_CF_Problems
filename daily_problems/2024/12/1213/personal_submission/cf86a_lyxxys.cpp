#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    vector <i64> pow10(10,1);
    for (int i = 1; i < 10; ++ i) pow10[i] = pow10[i-1] * 10;

    auto call = [&](i64 x)->i64{
        i64 y = 0, cur = x, cnt = 0;
        while (cur) cur /= 10, cnt += 1;

        for (int i = 0; i < cnt; ++ i){
            int c = (x/pow10[i])%10;
            y += pow10[i] * (9 - c);
        }

        return x*y;
    };

    i64 l, r;
    cin >> l >> r;
    i64 cur = 1;
    while (cur*10 <= r){
        cur *= 10;
    }
    i64 mid = cur*5;
    i64 res = 0;
    if (r < mid){
        res = call(r);
    } else {
        if (l <= mid) res = call(mid);
        else res = call(l);
    }

    cout << res << "\n";
}

