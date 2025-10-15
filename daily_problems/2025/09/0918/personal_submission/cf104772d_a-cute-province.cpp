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
/*
    如果 a 和 m 互质，那么 a^φ(m) ≡ 1 (mod m)φ(m) 是欧拉函数 表示小于或等于 m 的正整数中与 m 互质的数的数目
    10^k ≡ 1 (mod d)
*/
void solve()
{
    int d, saved;
    cin >> d;

    saved = d;

    while (d % 2 == 0) d /= 2;
    while (d % 5 == 0) d /= 5;

    int cur = 0, tot = 0;

    for (int i = 1; i <= 1000000; i ++) {
        cur = (10ll * cur + 9) % d;
        tot = (tot + 9) % saved;

        if (cur == 0 && tot == 0){
            cout << string(i, '9') << string(10, '0');
            return;
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
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
