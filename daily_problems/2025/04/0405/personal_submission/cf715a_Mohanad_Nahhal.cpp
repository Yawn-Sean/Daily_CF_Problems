/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (long long i = 1; i <= n; i ++) {
        // last -> i * i * (i + 1) * (i + 1) by adding i
        // i * (i - 1) + x * i = i * i * (i + 1) * (i + 1)
        // (i - 1) + x = i * (i + 1) * (i + 1)
        // x = i * (i + 1) * (i + 1) - (i - 1)  
        long long ans = i * (i + 1) * (i + 1) - (i - 1);
        if (i == 1) ans -= 2;

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
