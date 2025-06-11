/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    long long ans = 0;
    vector b(s.size() + 1, 0ll);

    set<int> c;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] != '.') continue;
        for (int j = i + 1; j < s.size(); j ++) {
            if ('a' <= s[j] && s[j] <= 'z') b[i] ++;
            else break;
        }
        c.insert(i);
    }
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] != '@') continue;
        long long num = 0;
        for (int j = i - 1; j >= 0; j --) {
            if (s[j] == '@' || s[j] == '.') break;
            if ('a' <= s[j] && s[j] <= 'z') num ++;
        }

        int j = -1;
        if (c.lower_bound(i) != c.end()) j = *c.lower_bound(i);
        
        int numm = 0;
        for (int z = i + 1; z < j; z ++) {
            if (s[z] == '_' || s[z] == '@') break;
            numm ++;
        }

        if (numm == j - i - 1 && numm) ans += num * b[j];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
