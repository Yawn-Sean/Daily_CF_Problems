//  C. How Does the Rook Move?

#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int mod = 1e9 + 7, M = 3e5;
    vector<int> dp(M + 1);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= M; i ++)
        dp[i] = (2ll * (i - 1) * dp[i - 2] + dp[i - 1]) % mod;

    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;

        while (k --) {
            int x, y;
            cin >> x >> y;

            if (x == y) n --;
            else n -= 2;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
