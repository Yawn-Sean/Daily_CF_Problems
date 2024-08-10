#include <bits/stdc++.h>

#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using pii = pair<int, int>;

constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
//constexpr int mod = 1e9 + 7;

using vd = vector<double>;
// dp
/*
 T O(3*n^2 + n)
 */
void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int mx = *max_element(all(a)),mi = *min_element(all(a));
    vector dp(3,vl(10008));
    double r = 1.0 /(1ll * n * (n-1) /2 );
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i]>a[j]) dp[0][a[i]-a[j]] += 1,dp[1][a[i]-a[j]]+= 1;
        }
    }
    for(int i=1;i<=mx-mi;++i){
        for(int j=1;j<=mx-mi;++j){
            dp[2][i+j] += dp[0][i] * dp[1][j];
        }
    }
    vl pre(10008);
    i64 ans = 0;
    for(int i=1;i<=2*(mx-mi);++i)
        pre[i+1]=pre[i]+ dp[2][i];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[j]>a[i]) ans += pre[a[j]-a[i]];
        }
    }

    cout << fixed << setprecision(10) << ans * r * r * r << endl;
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}






