#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;

    vector <int> A(n+1), B(n+1), C(n+1);
    vector <vector<int>> f(n+2, vector<int>(2));

    for (int i = 1; i <= n; ++ i) cin >> A[i];
    for (int i = 1; i <= n; ++ i) cin >> B[i];
    for (int i = 1; i <= n; ++ i) cin >> C[i];

    f[1][1] = -1e9;
    for (int i = 2; i <= n+1; ++ i){
        f[i][0] = max(f[i-1][1]+C[i-1], f[i-1][0]+B[i-1]);
        f[i][1] = max(f[i-1][1]+B[i-1], f[i-1][0]+A[i-1]);
    }

    cout << f[n+1][1] << "\n";
}
