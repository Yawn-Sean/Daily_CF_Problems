#include <bits/stdc++.h>

using namespace std;
char* fmt_str = "%%0%dd";
char fmt[5];
char buff[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) {
        cin >> x;
    }
    vector<string> ans(n);
    map<pair<int, int>, int> occs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            int x = 0;
            for (int k = 1; k <= 9 - j; k++) {
                x = x * 10 + (s[i][j + k - 1] - '0');
                pair<int, int> key = make_pair(k, x);
                if (occs.find(key) == occs.end()) {
                    occs[key] = i;
                } else if (occs[key] != i) {
                    occs[key] = -1;
                }
            }
        }
    }

    for (auto&[sb, idx] : occs) {
        if (idx != -1) {
            auto& [k, x] = sb;
            if (ans[idx].empty() || ans[idx].length() > k) {
                sprintf(fmt, fmt_str, k);
                sprintf(buff, fmt, x);
                ans[idx] = string(buff, k);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

