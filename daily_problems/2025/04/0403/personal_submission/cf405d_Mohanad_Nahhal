/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, op = 0;
    cin >> n;

    vector ans(0, 0), did(1000001, 0);
    for (int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x;
        did[x] = 1;
        y = 1e6 - x + 1;
        if (did[y]) op ++;
    }
    for (int i = 1; i <= 1e6; i ++) {
        if (did[i] == 0 && did[1000000 - i + 1] == 0 && op) {
            op --;
            ans.push_back(i);
            ans.push_back(1e6 - i + 1);
        }
        if (did[i] == 0 && did[1000000 - i + 1]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << ' ';
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
