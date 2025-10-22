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
    int x = 0, y = 0;
    vector<PII> ans;
    ans.emplace_back(0, 0);
    if(n == 3){
        cout << "0 0\n4 3\n-20 21\n";
        return ;
    }
    if(n&1){
        ans.emplace_back(12, 9);
    }
    for(int i = 4; i <= n; i += 2){
        y += 25;
        ans.emplace_back(x, y);
        x += 25;
        ans.emplace_back(x, y);
    }
    ans.emplace_back(x, 0);
    for(auto [x, y] : ans)cout << 4*x-3*y <<' ' <<3*x+4*y <<'\n';
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
