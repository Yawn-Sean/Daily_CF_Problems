#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long res = 1ll << 31;
    if (a%2 == b%2) fmin(res, max(a, b));
    if (a%2 == c%2) fmin(res, max(a, c));
    if (b%2 == c%2) fmin(res, max(b, c));

    cout << res << "\n";
}
