#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    long long all = 0;
    vector <int> A(n), ans(n, 1);
    for (auto &x : A) cin >> x;
    long long cur = A[n-1];
    for (int i = n-2; i >= 0; -- i){
        if (cur < 0){
            cur += A[i];
        } else {
            cur -= A[i];
            ans[i] = 0;
        }
    }
    if (cur < 0){
        for (auto &x : ans){
            x ^= 1;
        }
    }

    for (int i = 0; i < n; ++ i){
        cout << (ans[i] ? '+' : '-');
    }
    cout << "\n";
}
