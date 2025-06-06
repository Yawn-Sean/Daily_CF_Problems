/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<pair<vector<int>, string>, vector<int>> mp;
    for (int i = 0; i < n; i ++) {
        string s, t;
        cin >> s >> t;
        vector<int> b(26, 0);
        for (auto x : t) b[x - 'a'] = 1;

        while (s.size()) {
            if (b[s.back() - 'a'] == 0) break;
            s.pop_back();
        }
        mp[{b, s}].push_back(i + 1);
    }
    cout << mp.size() << endl;
    for (auto [_, group] : mp) {
        cout << group.size() << ' ';
        for (auto x : group) cout << x << ' ';
        cout << endl;
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
