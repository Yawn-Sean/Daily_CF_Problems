#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int n = 1000;
    cout << 2*n << "\n";
    for (int i = 1; i <= n; ++ i){
        cout << i << " " << 1 << " " << i << " " << 2 << "\n";
    }
    for (int i = n; i >= 1; -- i){
        cout << i << " " << 1 << " " << i << " " << 2 << "\n";
    }
}
