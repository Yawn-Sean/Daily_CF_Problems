#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '.' && s[i + 1] == '.') ans++;
    }
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        if (c == '.' && isalpha(s[pos])) {
            if (pos > 0 && s[pos - 1] == '.') ans++;
            if (pos < n - 1 && s[pos + 1] == '.') ans++;
        } else if (isalpha(c) && s[pos] == '.') {
            if (pos > 0 && s[pos - 1] == '.') ans--;
            if (pos < n - 1 && s[pos + 1] == '.') ans--;
        }
        s[pos] = c;
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}