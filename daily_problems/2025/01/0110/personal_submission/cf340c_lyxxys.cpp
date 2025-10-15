#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    int n;
    cin >> n;
    vector <i64> A(n), Pre(n+1);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; ++ i){
        Pre[i+1] = Pre[i] + A[i];
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++ i){
        i64 lst = Pre[i], nxt = Pre[n]-Pre[i+1];
        i64 x = A[i];
        ans += (i*x - lst) + (nxt - (n-i-1)*x) + x;
    }

    i64 d = __gcd(ans, 1ll*n);
    ans /= d, n /= d;

    cout << ans << " " << n << "\n";
}
