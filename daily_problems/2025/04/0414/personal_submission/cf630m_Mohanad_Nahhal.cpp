/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    int num = 0;
    const int c = 360;
    cin >> n;

    n = (-n % c + c) % c;
    vector did(c + 1, 1000000), vis(c + 1, 0);
    while (vis[n] == 0) {
        did[n] = min(did[n], num);
        did[c - n] = min(did[c - n], num);
        vis[n] = 1;
        num ++;
        n = (n + 90) % c;
    }
    for (int i = 0; i < c; i ++) {
        if (did[i] < 100) {
            cout << did[i] << endl;
            return;
        }
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
