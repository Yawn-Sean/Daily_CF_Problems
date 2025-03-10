#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> dp(n+1);
    dp[1] = 20;
    for(int i=2; i<=n; i++) {
        int p1 = lower_bound(a.begin(), a.end(), a[i]-89) - a.begin();
        int p2 = lower_bound(a.begin(), a.end(), a[i]-1439) - a.begin();
        dp[i] = dp[i-1] + 20;
        p1 = max(0, p1-1);
        p2 = max(0, p2-1);
        dp[i] = min(dp[i], dp[p1] + 50);
        dp[i] = min(dp[i], dp[p2] + 120);
        // cout << i << " " << p1 << " " << p2 << " " << dp[i] << endl;
    }
    for(int i=1; i<=n; i++)
        cout << dp[i] - dp[i-1] << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
