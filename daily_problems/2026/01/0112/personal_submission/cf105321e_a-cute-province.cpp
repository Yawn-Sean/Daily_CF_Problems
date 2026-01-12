#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
void solve() {
    int n, v;
    cin >> n >> v;
    vector<array<int, 3>> ve;
    for(int i = 1; i <= n; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        ve.push_back({a, b, c});
    }
    sort(ve.begin(), ve.end(), [&](array<int, 3> i, array<int, 3> j){
        return i[1] + i[0] * j[1] < j[1] + j[0] * i[1];
    });
    vector<int> dp(v+1);
    for(int i = n-1; i >=0 ; i --){
        for(int j = v; j >= ve[i][1]; j --){
            dp[j] = max(dp[j], dp[(j-ve[i][1])/ve[i][0]] + ve[i][2]);
        }
    }
    //for(int i = 0; i <= v; i ++)cout << dp[i] <<' ';
    cout << dp[v] <<'\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
