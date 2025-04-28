/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;

    vector a(n + 1, 0), len = a, where = a;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        where[a[i]] = i;
        len[i] = len[where[a[i] - 1]] + 1;
        ans = max(ans, len[i]);
    }
    cout << n - ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
