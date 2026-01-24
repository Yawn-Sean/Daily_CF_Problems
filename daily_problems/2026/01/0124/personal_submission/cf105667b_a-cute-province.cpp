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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int> (m+1));
    vector<vector<int>> ans22(n+1, vector<int> (m+1));
    vector<vector<int>> ans13(n+1, vector<int> (m+1));
    vector<vector<int>> ans31(n+1, vector<int> (m+1));
    for(int i = 1; i <= n;i ++){
        for(int j = 1; j <= m; j ++)cin >> g[i][j];
    }
    for(int i = 1; i <= n;i ++){
        for(int j = 1; j <= m - 2; j ++){
            if(g[i][j] == g[i][j+1] && g[i][j+1] == g[i][j+2])ans13[i][j] = 1;
            ans13[i][j] += ans13[i-1][j] + ans13[i][j-1] - ans13[i-1][j-1];
        }
    }
    for(int i = 1; i <= n-2; i ++){
        for(int j = 1; j <= m; j ++){
            if(g[i][j] == g[i+1][j] && g[i+1][j] == g[i+2][j])ans31[i][j] = 1;
            //cout << ans31[i][j] <<' ';
            ans31[i][j] += ans31[i-1][j] + ans31[i][j-1] - ans31[i-1][j-1];
        }
       // cout << '\n';
    }
    for(int i = 1; i <= n-1; i ++){
        for(int j = 1; j <= m-1;j ++){
            if(g[i][j] == g[i+1][j] && g[i][j] == g[i][j+1] && g[i][j] == g[i+1][j+1])ans22[i][j] = 1;
            ans22[i][j] += ans22[i-1][j] + ans22[i][j-1] - ans22[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++;
        y1++;
        x2++;
        y2++;
        int ok = 1;
        if(x2 > x1 && y2 > y1 && ans22[x2-1][y2-1] - ans22[x2-1][y1-1] - ans22[x1-1][y2-1] + ans22[x1-1][y1-1] > 0)ok = 0;
        if(y2-2 >= y1 && ans13[x2][y2-2] - ans13[x2][y1-1] - ans13[x1-1][y2-2] + ans13[x1-1][y1-1] > 0)ok = 0;
        if(x2 -2 >= x1 && ans31[x2-2][y2] - ans31[x2-2][y1-1] - ans31[x1-1][y2] + ans31[x1-1][y1-1] > 0)ok = 0;
        if(ok)cout << "YES\n";
        else cout << "NO\n";
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
