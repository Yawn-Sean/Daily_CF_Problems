#include <bits/stdc++.h>
using namespace std;

static vector<int> z_function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<string>> grid(n, vector<string>(n));
    vector<vector<int>> gl(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            gl[i][j] = (int)grid[i][j].size();
        }

    if (n >= 3) {
        int c01 = gl[0][1], c02 = gl[0][2], c12 = gl[1][2];
        long long sum = 1LL * c01 + c02 + c12;
        if (sum & 1) { cout << "NONE"; return 0; }
        int s012 = (int)(sum / 2);

        vector<int> cnt(n, 0);
        cnt[0] = s012 - c12;
        cnt[1] = s012 - c02;
        cnt[2] = s012 - c01;
        if (cnt[0] <= 0 || cnt[1] <= 0 || cnt[2] <= 0) { cout << "NONE"; return 0; }

        for (int i = 3; i < n; ++i) {
            cnt[i] = gl[0][i] - cnt[0];
            if (cnt[i] <= 0) { cout << "NONE"; return 0; }
        }

        vector<string> atom(n);
        for (int i = 0; i < n; ++i) {
            int j = (i == 0 ? 1 : 0);
            if (cnt[i] > gl[i][j]) { cout << "NONE"; return 0; }
            atom[i] = grid[i][j].substr(0, cnt[i]);
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) if (i != j) {
                if ((int)(atom[i].size() + atom[j].size()) != gl[i][j]) { cout << "NONE"; return 0; }
                if (atom[i] + atom[j] != grid[i][j]) { cout << "NONE"; return 0; }
            }

        cout << "UNIQUE\n";
        for (auto &s : atom) cout << s << '\n';
    } else {
        const string &s01 = grid[0][1];
        const string &s10 = grid[1][0];
        if (s01.size() != s10.size()) { cout << "NONE"; return 0; }
        int k = (int)s01.size();

        string t = s10 + '#' + s01 + s01;
        auto z = z_function(t);

        vector<int> idxs;
        int base = (int)s10.size() + 1;
        for (int cut = 1; cut < k; ++cut) {   
            int pos = base + cut;                     
            if (pos < (int)z.size() && z[pos] >= k)    
                idxs.push_back(cut);
        }

        if (idxs.empty()) cout << "NONE";
        else if ((int)idxs.size() > 1) cout << "MANY";
        else {
            int cut = idxs[0];
            cout << "UNIQUE\n";
            cout << s01.substr(0, cut) << '\n' << s01.substr(cut) << '\n';
        }
    }
    return 0;
}
