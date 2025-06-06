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
    map<int, int> cnt;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int mex = n;
    for(int i=0; i<=n-1; i++) {
        if(!cnt.count(i)) {
            mex = i;
            break;
        }
    }
    vector<int> dp(mex+1, 1e9);
    dp[mex] = 0;
    for(int i=mex-1; i>=0; i--) {
        for(int j=mex; j>=i+1; j--) {
            dp[i] = min(dp[i], (cnt[i]-1)*j + i + dp[j]);
        }
    }
    cout << dp[0] << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
