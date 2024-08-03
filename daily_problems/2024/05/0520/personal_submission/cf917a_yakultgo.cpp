#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(')
                cur++;
            else if (s[j] == ')')
                cur--;
            else {
                if (cur > 0) {
                    cur--;
                    cnt++;
                } else {
                    cur++;
                }
            }
            if (cur < 0 && cnt) {
                cur += 2;
                cnt--;
            }
            if (cur < 0 && !cnt) {
                break;
            }
            if (cur == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
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