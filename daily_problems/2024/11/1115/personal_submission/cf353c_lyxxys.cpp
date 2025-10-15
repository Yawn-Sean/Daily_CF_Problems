#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> A(n), Pr(n+1);
    for (auto &x : A) cin >> x;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++ i){
        Pr[i+1] = Pr[i] + A[i];
        if (s[i] == '1') res += A[i];
    }

    for (int i = n-1, cur = 0; i >= 0; -- i){
        if (s[i] == '1'){
            fmax(res, cur+Pr[i]);
            cur += A[i];
        }
    }

    cout << res << "\n";
}
