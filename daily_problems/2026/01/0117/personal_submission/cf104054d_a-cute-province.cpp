#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
void solve()
{
    int n;
    cin >> n;
    int mav1 = -1e9, mav2 = -1e9, miv1 = 1e9, miv2 = 1e9;
    for(int i = 1; i <= n; i ++){
        int x, y;
        cin >> x >> y;
        mav1 = max(mav1, x+y);
        miv1 = min(miv1, x+y);
        mav2 = max(mav2, x-y);
        miv2 = min(miv2, x-y);
    }
    if(n == 1){
        cout << 4 << '\n';
        return ;
    }
    int d1 = abs(mav1 - miv1) + 2, d2 = abs(mav2 - miv2) + 2;
    //cout << d1 <<' ' << d2 << '\n';
    if(d1 == 2 || d2 == 2){
        cout << d1 + d2 +1 << '\n';
    }
    else cout << d1 + d2 << '\n';
}
int cute_prov0nce()
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
