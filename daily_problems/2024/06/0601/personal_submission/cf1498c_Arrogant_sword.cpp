
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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector dp(n+1, vector<int>(k+1));
    for (int j = 1; j <= k; j ++ ) {
        dp[0][j] = 1;
        for (int i = 1; i <= n; i ++ ) {
            dp[i][j] = (dp[i-1][j], dp[n-i][j - 1]) % mod;
        }
    }

    cout << dp[n][k] << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}