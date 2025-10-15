#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

vector<int> prep(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    int j = 0;
    for (int i = 1; i < n; i ++) {
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j ++;
        pi[i] = j;
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<string>> grid(n, vector<string>(n));
    vector<vector<int>> grid_len(n, vector<int>(n));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> grid[i][j];
            grid_len[i][j] = grid[i][j].size();
        }
    }

    if (n >= 3) {
        int c01 = grid_len[0][1];
        int c02 = grid_len[0][2];
        int c12 = grid_len[1][2];

        int c012 = (c01 + c02 + c12) / 2;
        
        vector<int> cnt(n);

        cnt[0] = c012 - c12;
        cnt[1] = c012 - c02;
        cnt[2] = c012 - c01;

        for (int i = 3; i < n; i ++)
            cnt[i] = grid_len[0][i] - cnt[0];
        
        for (int i = 0; i < n; i ++)
            if (cnt[i] <= 0)
                return cout << "NONE", 0;
        
        vector<string> ans(n);

        for (int i = 0; i < n; i ++)
            ans[i] = grid[i][i ? 0 : 1].substr(0, cnt[i]);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && ans[i] + ans[j] != grid[i][j]) {
                    return cout << "NONE", 0;
                }
            }
        }

        cout << "UNIQUE\n";
        for (auto &x: ans) cout << x << '\n';
    }
    else {
        string s01 = grid[0][1], s10 = grid[1][0];

        if (s01.size() != s10.size())
            return cout << "NONE", 0;
        
        int k = s01.size();

        string tmp = s10;
        tmp += '#';
        tmp += s01;
        tmp += s01;

        auto kmp = prep(tmp);

        vector<int> idxs;
        for (int i = 2 * k + 1; i < 3 * k; i ++) {
            if (kmp[i] == k) {
                idxs.emplace_back(i - 2 * k);
            }
        }

        if (idxs.size() > 1) cout << "MANY";
        else if (idxs.empty()) cout << "NONE";
        else {
            int idx = idxs[0];
            cout << "UNIQUE\n";
            cout << s01.substr(0, idx) << '\n' << s01.substr(idx);
        }
    }

    return 0;
}