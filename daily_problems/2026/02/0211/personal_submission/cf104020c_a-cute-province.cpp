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
double E[2005], f[2005];
/*
    f[v] = f[v-1] + (1-p) * 1 + p * (1 + r + f[v]);
    f[v] = (f[v-1] + 1 + pr) / (1 - p);
*/
void solve()
{
    int c, t, r;
    cin >> c >> t >> r;
    double p;
    cin >> p;
    f[0] = 0;
    for(int i = 1; i <= c; i ++){
        f[i] = (f[i-1] + 1 + p * r) / (1 - p);
    }
    E[0] = 0;
    for(int i = 1; i <= c;i ++){
        E[i] = 1e18;
        for(int j = 0; j < i; j ++){
            E[i] = min(E[i], E[j] + f[i-j] + t);
        }
    }
    cout << fixed << setprecision(10) << E[c] << '\n';
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
