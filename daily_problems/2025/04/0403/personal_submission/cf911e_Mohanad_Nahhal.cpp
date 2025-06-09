/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector ans(0, 0), did(n + 1, 0), s(0, 0);
    for (int i = 1; i <= k; i ++) {
        int x;
        cin >> x;
        did[x] = 1;
        ans.push_back(x);
    }

    for (int i = 1; i <= n; i ++) {
        if (did[i]) {
            while (s.size()) {
                ans.push_back(s.back());
                s.pop_back();
            }
            s.clear();
            continue;
        }
        s.push_back(i);
    }

    while (s.size()) {
        ans.push_back(s.back());
        s.pop_back();
    }

    vector b(0, 0);
    for (int i = 0; i < n; i ++) {
        s.push_back(ans[i]);
        while (b.size() + 1 == s.back()) {
            b.push_back(s.back());
            s.pop_back();
        } 
    }


    if (b.size() != n) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i ++) {
        if (b[i] > b[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }

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
