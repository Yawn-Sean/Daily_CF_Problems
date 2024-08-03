#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntD = count(s.begin(), s.end(), 'D');
    int cntR = count(s.begin(), s.end(), 'R');
    if (cntD == 0 || cntR == 0) {
        cout << n << endl;
        return;
    }
    int pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[0]) {
            pos = i;
            break;
        }
    }
    ll ans = pos + 1ll * n * (n - pos);
    int dx = 0, dy = 0;
    for (int i = pos; i < s.size(); i++) {
        if (s[i] == 'R')
            dy++;
        else
            dx++;
    }
    ans -= 1ll * dx * dy;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}