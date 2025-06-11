#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 110;
int dp[N][N];
void solve() {
    int n, m;
    cin >> n >> m;
    auto cal = [&](int x, int y) -> int {
        if (dp[x][y]) return dp[x][y];
        for (int i = 1; i <= 26; i++) {
            if (dp[x - 1][y] != i && dp[x + 1][y] != i && dp[x][y - 1] != i && dp[x][y + 1] != i) {
                return i;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j]) continue;
            int x = cal(i, j);
            int k = 0;
            while (cal(i, j + k) == x && i + k <= n && j + k <= m) k++;
            for (int l = 0; l < k; l++) {
                for (int r = 0; r < k; r++) {
                    dp[i + l][j + r] = x;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << char('A' + dp[i][j] - 1);
        }
        cout << endl;
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