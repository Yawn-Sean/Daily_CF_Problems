#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
int dp[105][105 * 105];
/*7 6 5 4 4*/
void solve()
{
   int n;
   cin >> n;
   vector<int> a(n+1), col(n+1);
   int sum = 0;
   for(int i = 1; i <= n; i ++)cin >> a[i], sum += a[i];
    if(sum & 1){
        cout << -1 << '\n';
        return ;
    }
    sum /= 2;
    dp[0][0] = 1;
   for(int i = 1; i <= n; i ++){
    for(int j = 0; j <= sum; j ++){
        if(j >= a[i])dp[i][j] |= dp[i-1][j], dp[i][j] |= dp[i-1][j-a[i]];
        else dp[i][j] |= dp[i-1][j];
    }
   }
   if(!dp[n][sum]){
    cout << -1 << '\n';
    return ;
   }
   int i = n, j = sum;
   while(i && j){
    if(dp[i-1][j]){
        i --;
    }
    else{
        j -= a[i];
        col[i] = 1;
        i--;
    }
   }
   vector<int> v1, v2;
   for(int i = 1 ; i<= n;i ++){
    if(col[i])v1.emplace_back(a[i]);
    else v2.emplace_back(a[i]);
   }
   int ans1 = 0, ans2 = 0;
   while(!v1.empty() || !v2.empty()){
    if(ans1 <= ans2){
        ans1 += v1.back();
        cout << v1.back() <<' ';
        v1.pop_back();
    }
    else{
        ans2 += v2.back();
        cout << v2.back() <<' ';
        v2.pop_back();
    }
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
