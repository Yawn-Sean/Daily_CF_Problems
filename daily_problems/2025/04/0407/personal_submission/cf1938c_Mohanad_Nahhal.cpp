/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector a(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    vector ans(100, -1);
    for (int i = 2; i <= n; i ++) {
        if (a[i] == 0) {
            cout << -1 << endl;
            return;
        }
        if (a[i] - a[i - 1] >= 2) {
            cout << -1 << endl;
            return;
        }

        int x = a[i - 1] - a[i];
        for (int j = 0; j <= x; j ++) {
            if (ans[j] == 0) {
                cout << -1 << endl;
                return;
            }
            ans[j] = 0;
        }
        if (ans[x + 1] == 1) {
            cout << -1 << endl;
            return;
        }
        ans[x + 1] = 1;
    }

    long long x = 0, num = 0, last = -1;
    for (long long i = 0, pw = 1; i < 62; i ++, pw *= 2) {
        if (ans[i] == 1) {
            x += pw;
            last = i;
            num ++;
        }
    }

    if (num > a[n]) {
        cout << -1 << endl;
        return;
    }

    num = a[n] - num;
    for (int i = last + 1; i < 100; i ++) { 
        if (num == 0) break;
        ans[i] = 1;
        num --;
    }

    x = 0;
    for (long long i = 0, pw = 1; i < 62; i ++, pw *= 2) {
        if (ans[i] == 1) x += pw;
    }

    for (int i = n; i >= 1; i --) {
        if (__builtin_popcountll(x) != a[i]) {
            cout << -1 << endl;
            return;
        }
        x --;
    }

    cout << x + 1 << endl;
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
