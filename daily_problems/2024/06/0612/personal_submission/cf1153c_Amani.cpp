#include <bits/stdc++.h>
using namespace std;

string solve(string s, int n) {
    if (n & 1 || s[0] == ')' || s[n-1] == '(') {
        return ":(";
    }
    int cnt_l = 0, cnt = 0;
    for (char c : s) {
        if (c == '(') {
            cnt_l++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;
        } else if (s[i] == ')') {
            cnt--;
        } else {
            if (cnt_l < n / 2) {
                s[i] = '(';
                cnt_l++;
                cnt++;
            } else {
                s[i] = ')';
                cnt--;
            }
        }
        if  (i < n-1 && cnt <= 0) {
            return ":(";
        }
    }
    return cnt == 0 ? s : ":(";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << '\n';
    return 0;
}