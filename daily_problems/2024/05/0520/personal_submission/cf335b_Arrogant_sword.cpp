
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char &ch: s) cnt[ch-'a'] ++;
    int n = s.size();
    if (n >= 3000) {
        for (int i = 0; i < 26; i ++ ) {
            if (cnt[i] >= 100) {
                for (int j = 0; j < 100; j ++ ) cout << (char)(i+'a');
                return;
            }
        }
    }
    vector dp(n, vector<int>(n));
    for (int i = 0; i < n; i ++ ) dp[i][i] = 1;
    for (int len = 2; len <= n; len ++ ) {
        for (int l = 0; l + len <= n; l ++ ) {
            int r = l + len - 1;
            if (s[l] == s[r]) {
                if (r == l + 1) dp[l][r] = 2;
                else dp[l][r] = dp[l+1][r-1] + 2;
            } else {
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
    }

    string ans;
    int l = 0, r = n-1;
    while (l < r) {
        if (s[l] == s[r]) {
            ans.push_back(s[l]);
            l ++;
            r --;
        } else if (dp[l][r] == dp[l+1][r]) l ++;
        else r --;
    }

    int m = SZ(ans);
    if (m >= 50) {
        string res = ans.substr(0, 50);
        cout << res;
        reverse(all(res));
        cout << res;
    } else {
        cout << ans;
        if (dp[0][n-1] % 2) cout << s[l];
        reverse(all(ans));
        cout << ans;
    }
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