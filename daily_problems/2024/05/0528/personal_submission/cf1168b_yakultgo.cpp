#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size(), r = len + 1;
    long long ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 1; i + 2 * j < len; j++)
            if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
                r = min(r, i + 2 * j);
                break;
            }
        ans += max(len - r, 0);
    }
    cout << ans << endl;
    return 0;
}