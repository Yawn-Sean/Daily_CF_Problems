#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n+1), vals(n+1);
    for (auto &x : A){
        cin >> x;
    }
    for (int i = 0; i < n; ++ i){
        vals[i+1] += (vals[i] + A[i]) / 2;
        vals[i] = (vals[i] + A[i]) % 2;
    }
    vals[n] += A[n];

    int idx = -1;
    for (int i = 0; i <= n; ++ i){
        if (vals[i] != 0){
            idx = i;
            break;
        }
    }

    long long cur = 0;
    int res = 0;
    for (int i = n; i >= 0; -- i){
        cur = cur*2 + vals[i];
        if (abs(cur) > 2*k) break;
        if (i <= idx && abs(A[i]-cur) <= k && !(i==n && A[i]==cur)){
            res += 1;
        }
    }

    cout << res << "\n";
}
