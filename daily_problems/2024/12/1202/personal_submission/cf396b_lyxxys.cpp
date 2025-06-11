#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    auto chk = [&](int x)->bool{
        for (long long i = 2; i*i <= x; ++ i){
            if (x%i == 0){
                return false;
            }
        }
        return true;
    };

    int n;
    cin >> n;
    int a = n, b = (n+1);
    while (!chk(a)) a -= 1;
    while (!chk(b)) b += 1;
    
    long long son = 1ll*a*b + 2*n + 2 - 2ll*(a+b);
    long long mom = 2ll*a*b;
    long long d = __gcd(son, mom);
    son /= d, mom /= d;
    cout << son << "/" << mom << "\n";
}
