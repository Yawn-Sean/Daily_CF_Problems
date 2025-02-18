#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 107;
int prefix[13][N][N];

void solve() {
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        prefix[s][x][y]++;
    }
    for (int t = 0; t <= c; t++) {
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                prefix[t][i][j] += prefix[t][i - 1][j] + prefix[t][i][j - 1] - prefix[t][i - 1][j - 1];
            }
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int i = 0; i <= c; i++) {
            int b = (i + t) % (c + 1);
            int cnt = prefix[i][x2][y2] - prefix[i][x1 - 1][y2] - prefix[i][x2][y1 - 1] + prefix[i][x1 - 1][y1 - 1];
            ans += (b * cnt);
        } 
        cout << ans << endl;
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    solve();
}

