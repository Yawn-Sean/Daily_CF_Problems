#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2610;
ll dp[101][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int mod = 1e9 + 7;
    dp[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= i * 26; j++) {
            for (int k = 1; k <= 26; k++) {
                if (j >= k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }
    }
    int T = 1;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i] - 'a' + 1;
        }
        cout << (dp[n][sum] - 1 + mod) % mod << endl;
    }
    return 0;
}