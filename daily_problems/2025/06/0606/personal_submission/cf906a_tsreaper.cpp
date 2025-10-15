#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int ans = 0, flag[26] = {0};
    bool found = false;
    for (int i = 1; i <= n; i++) {
        string op, s;
        cin >> op >> s;
        if (op == ".") {
            for (char c : s) flag[c - 'a'] = -1;
        } else if (op == "!") {
            bool has[26] = {0};
            for (char c : s) has[c - 'a'] = true;
            for (int c = 0; c < 26; c++) if (!has[c]) flag[c] = -1;
            if (found) ans++;
        } else if (op == "?") {
            if (i < n) {
                flag[s[0] - 'a'] = -1;
                if (found) ans++;
            }
        }
        int zero = 0;
        for (int j = 0; j < 26; j++) if (flag[j] == 0) zero++;
        if (zero == 1) found = true;
    }
    printf("%d\n", ans);
    return 0;
}
