#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> gs(n);
    vector<string> substrs(n * 2 - 2);
    for (int i = 0; i < n * 2 - 2; i++) {
        cin >> substrs[i];
        gs[substrs[i].length()].push_back(i);
    }
    auto is_prefix = [&] (string& txt, string& pf) -> bool {
        int m = pf.length();
        for (int i = 0; i < m; i++) {
            if (pf[i] != txt[i]) return false;
        }
        return true;
    };
    auto is_suffix = [&] (string& txt, string& sf) -> bool {
        int m = sf.length();
        for (int i = m - 1; i >= 0; i--) {
            if (sf[i] != txt[n - (m - i)]) return false;
        }
        return true;
    };
    string ans(2 * n - 2, ' ');
    array<pair<int, int>, 2> texts{make_pair(gs[n - 1][0], gs[n - 1][1]), make_pair(gs[n - 1][1], gs[n - 1][0])};
    for (auto& [i1, i2] : texts) {
        bool valid = true;
        string text = substrs[i1] + substrs[i2].substr(n - 2);
        for (int i = 1; i < n - 1; i++) {
            int j1 = gs[i][0];
            int j2 = gs[i][1];
            if (is_prefix(text, substrs[j1]) && is_suffix(text, substrs[j2])) {
                ans[j1] = 'P';
                ans[j2] = 'S';
            } else if (is_prefix(text, substrs[j2]) && is_suffix(text, substrs[j1])) {
                ans[j1] = 'S';
                ans[j2] = 'P';
            } else {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans[i1] = 'P';
            ans[i2] = 'S';
            break;
        }
        fill(ans.begin(), ans.end(), ' ');
    }
    cout << ans << "\n";
    return 0;
}

