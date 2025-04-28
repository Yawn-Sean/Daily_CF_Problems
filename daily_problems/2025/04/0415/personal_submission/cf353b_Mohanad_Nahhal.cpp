/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    n *= 2;

    vector a(n + 1, string());
    vector b(0, 0), c(0, 0);
    map<string, vector<int>> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    vector ones(0, string()), evens(0, string()), odds(0, string());
    for (auto [x, y] : mp) {
        if (y.size() == 1) ones.push_back(x);
        else if (y.size() % 2) odds.push_back(x);
        else evens.push_back(x);
    }

    for (auto x : ones) {
        int f = 0;
        if (c.size() < b.size()) f = 1;
        for (auto y : mp[x]) {
            if (f == 0) b.push_back(y);
            else c.push_back(y);
            f ^= 1;
        }
    }

    for (auto x : odds) {
        int f = 0;
        if (c.size() < b.size()) f = 1;
        for (auto y : mp[x]) {
            if (f == 0) b.push_back(y);
            else c.push_back(y);
            f ^= 1;
        }
    }

    for (auto x : evens) {
        int f = 0;
        for (auto y : mp[x]) {
            if (f == 0) b.push_back(y);
            else c.push_back(y);
            f ^= 1;
        }
    }

    map<string, int> mpp;
    for (int i = 0; i < b.size(); i ++) {
        for (int j = 0; j < c.size(); j ++) {
            string s = a[b[i]];
            s += a[c[j]];
            mpp[s] ++;
        }
    }
    cout << mpp.size() << endl;
    vector ans(n + 1, 0);
    for (auto x : b) ans[x] = 1;
    for (auto x : c) ans[x] = 2;

    for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
