#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    map <vector<int>, int> mps;
    vector <vector<int>> A(m);
    for (int i = 0, g; i < n; ++ i){
        cin >> g;
        for (int j = 0, x; j < g; ++ j){
            cin >> x;
            x -= 1;
            A[x].push_back(i);
        }
    }

    const int mod = 1e9+7;
    int res = 1;
    for (int i = 0; i < m; ++ i){
        mps[A[i]] += 1;
        res = 1ll * res * mps[A[i]] % mod;
    }

    cout << res << "\n";
}
