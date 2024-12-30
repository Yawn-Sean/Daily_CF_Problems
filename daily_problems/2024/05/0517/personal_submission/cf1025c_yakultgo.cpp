#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    n = s.size();
    int ans = 1;
    int t = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            t++;
            ans = max(ans, t);
        } else {
            t = 1;
        }
    }
    cout << min(ans, n / 2) << endl;
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