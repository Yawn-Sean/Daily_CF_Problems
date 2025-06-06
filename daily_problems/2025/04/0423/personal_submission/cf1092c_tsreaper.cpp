#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<vector<string>> s(n);
    vector<vector<int>> idx(n);
    for (int i = 0; i < (n - 1) * 2; i++) {
        string tmp; cin >> tmp;
        s[tmp.size()].push_back(tmp);
        idx[tmp.size()].push_back(i);
    }
    if (n == 2) { cout << "PS\n"; return 0; }

    auto check = [&](string goal) {
        string ans;
        ans.resize((n - 1) * 2);
        for (int i = 1; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < 2; j++) if (s[i][j] == goal.substr(0, i) && s[i][j ^ 1] == goal.substr(n - i, i)) {
                ans[idx[i][j]] = 'P';
                ans[idx[i][j ^ 1]] = 'S';
                ok = true;
                break;
            }
            if (ok) continue;
            return false;
        }
        cout << ans << "\n";
        return true;
    };

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) if (check(s[1][i] + s[n - 1][j].substr(1, n - 2) + s[1][i ^ 1])) return 0;
    return 0;
}
