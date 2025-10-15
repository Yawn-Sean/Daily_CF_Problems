#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1),dp(n+1);
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+20;
        int it1=upper_bound(a.begin()+1,a.begin()+i+1,a[i]-90)-a.begin();
        int it2=upper_bound(a.begin()+1,a.begin()+i+1,a[i]-1440)-a.begin();
        // cout<<it1<<' '<<it2<<endl;
        dp[i]=min(dp[i],dp[it1-1]+50);
        dp[i]=min(dp[i],dp[it2-1]+120);
        cout<<dp[i]-dp[i-1]<<endl;
    }
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
