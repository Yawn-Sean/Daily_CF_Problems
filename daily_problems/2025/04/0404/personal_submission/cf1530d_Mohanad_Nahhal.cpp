/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector a(n + 1, 0), b(n + 1, 0), did(n + 1, 0), c(n + 1, 0);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (did[a[i]] == 0) {
            ans ++;
            b[i] = a[i];
            did[a[i]] = 1;
            c[b[i]] = i;
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        if (b[i]) continue;
        if (c[i]) {
            int y;
            function<void(int)> dfs = [&] (int x) {
                y = x;
                if (c[x]) dfs(c[x]);
            };
            dfs(i);
            b[i] = y;
            c[b[i]] = i;
        }   
        else {
            b[i] = a[i];
            int y = c[b[i]];
            b[y] = i;

            c[b[i]] = i;
            c[i] = y; 
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; i ++) cout << b[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
