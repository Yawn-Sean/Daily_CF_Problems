#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> vc(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; ++i) {
        vc[i][s[i - 1] - 'a']++;
        for (int j = 0; j < 26; ++j) vc[i][j] += vc[i - 1][j];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> cur(26, 0);
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            cur[i] = vc[r][i] - vc[l - 1][i];
            if (cur[i]) ++cnt;
        }
        if (cnt >= 3) {
            cout << "Yes\n";
        } else if (cnt == 2) {
            if (s[l - 1] == s[r - 1]) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            if (r > l) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
