#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, pos, cntx = 0, cnty = 0;
    string s;
    cin >> n >> s;
    long long ans = 1LL * n * n;
    for (pos = 0; pos < s.size(); pos++) {
        if (s[pos] != s[0]) {
            ans -= 1LL * pos * (n - 1);
            break;
        }
    }
    if (pos == s.size()) ans = n;
    for (int i = pos; i < s.size(); i++) {
        if (s[i] == 'R') cntx++;
        else cnty++;
    }
    ans -= 1LL * cntx * cnty;
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
