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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int> (m+1));
    vector<int> cnt(n*m+1), num;
    num.emplace_back(0);
    for(int i = 1; i <= n; i ++){
        for(int j =1; j <= m;  j ++)cin >> a[i][j], cnt[a[i][j]] ++, num.emplace_back(a[i][j]);
    }
    for(int i = 1; i <= n*m;i  ++)cnt[i] += cnt[i-1];
    sort(num.begin(), num.end());
    for(int k = 1; k <= n; k ++){
        int cur = k, start = 0;
        for(int j = 1; j <= m; j ++){
            start += cur;
            cur = min(cur, start - cnt[num[start]-1]);
            cout << num[start] <<' ';
        }
        cout << '\n';
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
