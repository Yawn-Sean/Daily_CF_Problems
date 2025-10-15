/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector a(6, 0);
    vector b(6, vector(0, 0));
    for (int i = 0; i < 6; i ++) cin >> a[i];
    map<string, int> mp;
    map<int, string> rmp;
    mp["S"] = 0, rmp[0] = "S";
    mp["M"] = 1, rmp[1] = "M";
    mp["L"] = 2, rmp[2] = "L";
    mp["XL"] = 3, rmp[3] = "XL";
    mp["XXL"] = 4, rmp[4] = "XXL";
    mp["XXXL"] = 5, rmp[5] = "XXXL";

    int n;
    cin >> n;
    vector ans(n, string());

    for (int i = 0; i < n; i ++) {
        string s, t;
        cin >> s;
        for (int j = 0; j < s.size(); j ++) {
            if (s[j] == ',') {
                t = s.substr(j + 1, s.size() - j);
                s = s.substr(0, j);
                break;
            }
        }
        if (t.size()) b[mp[s]].push_back(i);
        else {
            if (a[mp[s]] == 0) {
                cout << "NO" << endl;
                return;
            }
            a[mp[s]] --;
            ans[i] = s;
        }
    }

    for (int i = 0; i < 5; i ++) {
        while (b[i].size()) {
            int x = b[i].back();
            b[i].pop_back();
            if (a[i]) {
                a[i] --;
                ans[x] = rmp[i];
            }
            else if (a[i + 1]) {
                a[i + 1] --;
                ans[x] = rmp[i + 1];
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i ++) cout << ans[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
