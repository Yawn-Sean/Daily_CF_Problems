#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <long long> A(n);
    for (auto &x : A) cin >> x;
    vector <int> ps(n), ans(n);
    iota(ps.begin(), ps.end(), 0);
    sort(ps.begin(), ps.end(), [&](int x, int y){
        return A[x]+A[(x+1)%n] < A[y]+A[(y+1)%n];
    }) ;
    for (int i = 0; i < n; ++ i){
        ans[ps[i]] = i;
    }
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}
