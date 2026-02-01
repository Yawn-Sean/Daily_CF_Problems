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
const double pi = acos(-1);
void solve()
{   
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ans;
    if(y1 == y2 || x1 == x2){
        ans = abs(x1-x2) + abs(y1-y2);
    }
    else{
        int r1 = abs(x1+y1), r2 = abs(x2+ y2);
        if(r1 > r2)swap(r1, r2);
        ans = (pi/2)*r1 + r2-r1;
        
    }
    cout << fixed << setprecision(6) << ans << '\n';
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
