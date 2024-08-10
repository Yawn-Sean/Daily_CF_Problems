#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    int tot = 0, cur = 0, cnt = 0, res = 2e3 * n;
    rep(i, 0, n * 2) {
        cin >> s;
        int m = s.size();
        cur = 0;
        rep(j, m - 3, m) {
            cur = cur * 10 + (s[j] - '0');
        }
        tot += cur;
        if (!cur) {
            cnt++;
        }
    }
    rep(i, max(0, n - cnt), min(n, 2 * n - cnt) + 1) {
        res = min(res, abs(i * 1000 - tot));
    }
    cout << res / 1000 << '.';
    res %= 1000;
    cout << res / 100 << res / 10 % 10 << res % 10 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}



