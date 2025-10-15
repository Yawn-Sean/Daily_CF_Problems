#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> dp(n+1,-1), ma(26,-1), w(26, -1), path(n+1);
    dp[0] = 0;
    for(int i =1 ; i <=n;i ++){
        if (ma[s[i]-'a'] != -1)dp[i] =  ma[s[i]-'a'] + 1, path[i] = w[s[i]-'a'];
        if(dp[i-1] > ma[s[i]-'a']){
            ma[s[i] - 'a'] = dp[i-1];
            w[s[i]-'a'] = i-1;
        }
    }
    vector<int> ans;
    if(dp[n] == -1)cout << -1 << '\n';
    else{
        cout << dp[n] << '\n';
        int st = n;
        while(st != 0){
            ans.emplace_back(st - path[st]);
            st = path[st];  
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i ++)cout << ans[i] <<' ';
    }



}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
