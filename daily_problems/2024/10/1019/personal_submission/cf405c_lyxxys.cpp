#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int N = 1000;
    int n;
    cin >> n;
    bitset <N> norm;
    vector<bitset<N>> row(n), col(n);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++ i) norm.set(i);

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            cin >> g[i][j];
            if (g[i][j]) row[i].set(j);
        }
    }
    for (int j = 0; j < n; ++ j){
        for (int i = 0; i < n; ++ i){
            if (g[i][j]) col[j].set(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += (row[i]&col[i]).count();
    }
    ans %= 2;
    int q;
    cin >> q;
    while (q--){
        int opt, i;
        cin >> opt;
        if (opt != 3){
            cin >> i;
            ans ^= 1;
        } else {
            cout << ans;
        }
    }
    cout << "\n";
}
