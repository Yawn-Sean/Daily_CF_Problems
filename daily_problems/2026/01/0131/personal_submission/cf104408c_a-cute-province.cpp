#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
void solve()
{   
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n+1, vector<int> (m+1));
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < m; j ++){
            char x;
            cin >> x;
            if(x == '1')s[i][j] = 1;
            else s[i][j] = 0;
        }
    }  
    vector<int> cnt(m);
    for(int i = 1; i <= n; i++){
        if(s[i][m-1])cnt[m-1] ++;
        for(int j = 0; j < m-1; j ++){
            if(s[i][j] != s[i][j+1])cnt[j] ++;
        }
    }
    int ans = 0;
    for(int j = 0; j < m; j ++){
        ans += min(n - cnt[j], cnt[j]);
    }
    cout << ans << '\n';

}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
