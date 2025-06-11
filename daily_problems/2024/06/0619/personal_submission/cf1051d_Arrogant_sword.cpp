
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 1010;
const int mod = 998244353;
int dp[N][4][2*N];

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    dp[1][0][1] = dp[1][3][1] = 1;
    dp[1][1][2] = dp[1][2][2] = 1;

    for (int i = 2; i <= n; i ++ ) {
            for (int k = 1; k <= m; k ++ ) {
                dp[i][0][k] = (dp[i][0][k] + dp[i-1][0][k] + dp[i-1][1][k] + dp[i-1][2][k] + dp[i-1][3][k - 1]) % mod;
                dp[i][1][k] = (dp[i][1][k] + dp[i-1][0][k - 1] + dp[i-1][1][k] + (k > 2 ? dp[i-1][2][k-2] : 0) + dp[i-1][3][k - 1]) % mod;
                dp[i][2][k] = (dp[i][2][k] + dp[i-1][0][k - 1] + (k  > 2 ? dp[i-1][1][k-2] : 0) + dp[i-1][2][k] + dp[i-1][3][k - 1]) % mod;
                dp[i][3][k] = (dp[i][3][k] + dp[i-1][0][k - 1] + dp[i-1][1][k] + dp[i-1][2][k] + dp[i-1][3][k]) % mod;
            }
        }
    

    int ans = 0;
    for (int i = 0; i < 4; i ++ ) {
        ans = (ans + dp[n][i][m] ) % mod;
    }
    cout << ans << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}