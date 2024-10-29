#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <array<int,2>> A(n);
    long long res = 0;
    for (auto &i : A){
        cin >> i[0] >> i[1];
        if (i[0] > i[1]) swap(i[0], i[1]);
        fmax(res, 1ll*i[0]*i[1]);
    }
    
    sort(A.begin(), A.end(), [&](array<int,2>&u, array<int,2>&v){
        return u[0] < v[0];
    });
    vector <int> suf(n+1);
    for (int i = n-1; i >= 0; -- i){
        suf[i] = max(suf[i+1], A[i][1]);
    }

    for (int i = 0; i < n-1; ++ i){
        fmax(res, 2ll * A[i][0] * min(A[i][1], suf[i+1]));
    }

    cout << res/2;
    if (res%2) cout << ".5";
    else cout << ".0";
    cout << "\n";
}
