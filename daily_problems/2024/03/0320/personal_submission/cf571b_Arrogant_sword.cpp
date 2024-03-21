// 将A中的下标按照%k分组，这样可以得到k组，每组互相独立，且最小贡献的情况为排序后，最贡献为最大值减去最小值。
// 考虑有多少个分组？ 余数 matter。
// 有n%k个长度为n/k+1的组，另外k-n%k个组的长度为n/k。
// 这个问题就变成了一共要选k个组，其中n%k个组的长度为n/k+1,其余组的长度为n/k，问最小贡献。这是个背包问题。
// dp[i][j]表示前i个组中有j个组的长度为n/k+1,转移方程：
// dp[i][j] = dp[i-1][j] + a[i*len+j] - a[(i-1)*len + j + 1],表示这一组为(i-1)*len+j+1 —— i*len+j。（长度为len）
// dp[i][j] = dp[i-1][j-1] + a[i*len+j] - a[(i-1)*len + j], (i-1)*len+j —— i*len+j, 长度为len+1。取min即可。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int inf = 1e12;
void solve() 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    a[0] = -inf;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(all(a));

    int x = n % k;
    int d = n/k;
    vector<vector<int>> dp(k+1, vector<int>(x+1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i ++ ) {
        for (int j = 1; j <= min(i, x); j ++ ) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i*d+j] - a[(i-1)*d+j+1]);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i*d+j] - a[(i-1)*d+j]);
        }
    }

    cout << dp[k][x] << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}