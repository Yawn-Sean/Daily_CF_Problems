#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve()
{
    int n, w, L;
    cin >> n >> w >> L;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= w; i++){
        int x, y;
            cin >> x >> y;
            a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2  + 1;
        auto check = [&]()->bool {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = i + mid -1, y = j + mid - 1;
                if (x > n || x < 0 || y > n || y < 0)continue;
                if (a[x][y] + a[i-1][j-1] - a[x][j-1] - a[i-1][y] <= L)return  true;
            }
        }
            return false;
    };
        if (check()) l = mid;
        else r = mid - 1;
    }
    cout << l * l <<  '\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
