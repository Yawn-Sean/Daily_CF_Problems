#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, pre = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            pre++;
        else {
            int r = i, cur = 1;
            for (int j = 1; j <= 18; j++) {
                if (cur <= pre + (r - i + 1)) ans++;
                r++;
                if (r >= n) break;
                cur = cur * 2 + (s[r] - '0');
            }
            pre = 0;
        }
    }
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