#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

int dp[2000007];
void solve()
{
    string s; cin >> s;
    int st = find(begin(s), end(s), 'M') - begin(s);
    int n = rend(s) - find(rbegin(s), rend(s), 'F');

    int sp = 0;
    for(int i = st; i < n; i ++){
        if(i) dp[i] = dp[i - 1];
        if(s[i] == 'M'){
            sp ++;
        } else {
            dp[i] = max(dp[i] + 1, sp);
        }
    }
    cout << dp[n - 1] << endl;
}   


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
