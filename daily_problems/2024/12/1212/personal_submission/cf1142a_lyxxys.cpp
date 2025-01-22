#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
using i64 = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;

    i64 ma = 0, mi = 1e18;
    
    long long L = 1ll*n*k;
    if (n > 1){
        long long j1=b-a,j2=-a-b,j3=a-b,j4=a+b;
        for (int i = 0; i < 2*n; ++ i){
            if (j1 > 0){
                fmax(ma, L / __gcd(L, j1));
                fmin(mi, L / __gcd(L, j1));
            }
            if (j2 > 0){
                fmax(ma, L / __gcd(L, j2));
                fmin(mi, L / __gcd(L, j2));
            }
            if (j3 > 0){
                fmax(ma, L / __gcd(L, j3));
                fmin(mi, L / __gcd(L, j3));
            }
            if (j4 > 0){
                fmax(ma, L / __gcd(L, j4));
                fmin(mi, L / __gcd(L, j4));
            }
            j1 += k, j2 += k, j3 += k, j4 += k;
            if (j1 > L) j1 -= L;
            if (j2 > L) j2 -= L;
            if (j3 > L) j3 -= L;
            if (j4 > L) j4 -= L;
        }
    }
    long long j = b-a >= 0 ? b-a : b-a+k;
    for (int i = 0; i < n+1; ++ i){
        if (j > 0 && j <= L){
            fmax(ma, L / __gcd(L, j));
            fmin(mi, L / __gcd(L, j));
        }
        j += k;
        if (j > L) j -= L;
    }

    cout << mi << " " << ma << "\n";
}
