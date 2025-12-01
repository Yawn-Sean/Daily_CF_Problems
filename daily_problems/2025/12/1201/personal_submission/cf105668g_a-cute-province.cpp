#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 1e6 + 10;
PII dx[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
void solve()
{
   int n, m;
   cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int> (m+1));
    vector<array<int,3>> ve;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++)cin >> a[i][j], ve.push_back({a[i][j], i, j});
    }
    int ans = 0;
    sort(ve.begin(), ve.end());
    for(auto v : ve){
        int x = v[1], y = v[2];
        int ma = -1;
        for(int i = 0 ; i < 4; i ++){
            int xx = x + dx[i].x, yy = y + dx[i].y;
            if(xx > n || xx < 1 || yy > m || yy < 1)continue;
            if(a[xx][yy] < a[x][y])ma = max(ma, a[xx][yy]);
        }
        ans += a[x][y] - (ma + 1);
        a[x][y] = ma+1;
    }
    if(ans & 1)cout << "Yes\n";
    else cout << "No\n";
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
