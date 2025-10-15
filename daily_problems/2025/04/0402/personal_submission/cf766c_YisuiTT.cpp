#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int MOD = 1e9 + 7;
void solve(){
    int n, a[30];
    string s;
    cin >> n >> s;
    for(int i = 0; i < 26; i++)cin >> a[i];
    vector<i64>dp(n + 1, 0);
    int maxx = 0, minn = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        vector<int>ch(26, 0);
        int len = i + 1;
        for(int j = i; j >= 0; j--){
            len = min(len, a[s[j] - 'a']);
            if(i - j + 1 <= len){
                dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
            }else break;
            maxx = max(maxx, i - j + 1);
        }
    }
    int i = 0;
    while(i < n){
        int j = i, len = a[s[j] - 'a'];
        vector<int>ch(26, 0);
        while(j < n && j - i + 1 <= len){
            j++;
            len = min(len, a[s[j] - 'a']);
        }
        // cout << s.substr(i, j - i) << '\n';
        minn ++;
        i = j;
    }
    cout << dp[n] << '\n';
    cout << maxx << '\n';
    cout << minn << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
