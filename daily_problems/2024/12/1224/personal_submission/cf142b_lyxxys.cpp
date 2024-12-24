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
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1){
        cout << max(n, m) << "\n";
    } else if (n == 2 || m == 2){
        int x = max(n, m);
        cout << (x/4*4 + min(x%4, 2)*2) << "\n";
    } else if (m%2 == 0){
        cout << m/2 * n << "\n";
    } else {
        cout << max(4, m/2*n + (n+1)/2) << "\n";
    }
}
