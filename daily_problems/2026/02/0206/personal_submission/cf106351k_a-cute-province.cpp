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
const int N = 1e5 + 10;
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> f(N+1);
    vector<int> cnt(N+1);
    for(int i = 1; i <= n; i ++){
        int val;
        cin >> val;
        cnt[val] ++;
    }
    for(int i = 1; i <= N; i ++){
        for(int j = i ; j <= N; j +=i)f[j].emplace_back(i);
    }
    /*
        因子个数最大100左右并且这些数很少。
    */
    int ans = 0, ma = 0;
    for(int i = x; i <= y; i ++){
        ans += (cnt[i]-1) * cnt[i]/2;
        for(int j = 0; j < (int)f[i].size(); j ++){
            for(int k = 0; k < j; k ++){
                if(f[i][j] * f[i][k] / std::gcd(f[i][j], f[i][k]) != i)continue;
                if(std::gcd(f[i][j], f[i][k]) >= x && std::gcd(f[i][j], f[i][k]) <= y)ans += cnt[f[i][j]] * cnt[f[i][k]];
            }
        }
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
