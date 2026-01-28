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
    int sx, sy, tx, ty, k;
    cin >> sx >> sy >> tx >> ty >> k;
    int dx = abs(sx - tx), dy = abs(sy - ty);
    if(dx > dy)swap(dx, dy);
    if(dx * k + k >= dy)cout << dx + dy << '\n';
    else{
        int cnt = (dy+k-1)/k - dx - 1;
        if(cnt & 1)cnt ++;
        cout << dx + dy + cnt << '\n';
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
