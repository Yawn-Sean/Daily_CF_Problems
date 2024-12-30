#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int x = 0, y = i;
        while (y < n) {
            if (s[x][y] == '1')
                sum++;
            x++, y++;
        }
        y %= n;
        while (x < n) {
            if (s[x][y] == '1')
                sum++;
            x++, y++;
        }
        mx = max(mx, sum);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += count(s[i].begin(), s[i].end(), '1');
    cout << (n - mx) + (cnt - mx) << endl;
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