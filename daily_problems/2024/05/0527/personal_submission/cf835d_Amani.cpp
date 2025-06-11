#include <iostream>
using namespace std;

int dp[5003][5003], a[5003], len = 0;
char s[5003];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    for (char c : str) {
        s[++len] = c;
    }
    for (int i = 1; i <= len; ++i) {
        dp[i][i] = 1;
        a[1]++;
        if (i > 1 && s[i] == s[i - 1]) {
            dp[i - 1][i] += 2;
            a[1]++;
            a[2]++;
        }
    }
    int l, r;
    for (int i = 3; i <= len; ++i) {
        for (l = 1; l + i - 1 <= len; ++l) {
            r = l + i - 1;
            if (!dp[l + 1][r - 1] || s[r] != s[l])
                continue;
            int mid = l + (r - l) / 2;
            if (i & 1) {
                dp[l][r] = dp[l][mid - 1] + 1;
            }
            else {
                dp[l][r] = dp[l][mid] + 1;
            }
            for (int k = dp[l][r]; k > 0; --k) {
                a[k]++;
            }
        }
    }
    for (int i = 1; i <= len; ++i)
        cout << a[i] << " ";
    return 0;
}