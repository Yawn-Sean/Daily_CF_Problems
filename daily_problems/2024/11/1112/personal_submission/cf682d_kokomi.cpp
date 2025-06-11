#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, k;
string s, t;
//考虑dp，dp[k][i][j]表示从前i个字符和j个字符中选k个公共子串的最大答案
int dp[11][N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> s >> t;
    for(int l = 1; l <= k; l++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]) dp[l][i][j] = max(dp[l - 1][i - 1][j - 1], dp[l][i - 1][j - 1]) + 1;
            }
        }
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[l][i][j] = max(dp[l][i][j], max(dp[l][i - 1][j],dp[l][i][j  -1]));
            }
        }
    }
    cout << dp[k][n][m] << endl;

}