#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<int> left(n), right(n);
    int ans = 0, cnt1 = 0;
    int sx = 0, sy = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt1 += (g[i][j] - '0');
        }
    }
    for (int i = 0; i < n; i++) {
        cnt += (g[sx][sy] - '0');
        sx++; sy++;
    }
    ans = cnt1 - cnt + (n - cnt);
    for (int i = 1; i < n; i++) {
        sx = 0, sy = i, cnt = 0;
        for (int j = 0; j < n - i; j++) {
            cnt += (g[sx][sy] - '0');
            sx++; sy++;
        }
        right[n - i] = cnt;
    } 
    for (int j = 1; j < n; j++) {
        sx = j, sy = 0, cnt = 0;
        for (int i = 0; i < n - j; i++) {
            cnt += (g[sx][sy] - '0');
            sx++; sy++;
        }
        left[n - j] = cnt;
    }
    for (int i = 1; i < n; i++) {
        cnt = left[i] + right[n - i];
        ans = min(ans, cnt1 - cnt + n - cnt);
    }
    cout << ans << "\n";
}
 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
