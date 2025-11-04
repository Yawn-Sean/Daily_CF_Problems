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
const int N = 3e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> x(2*n), y(2*n);
    vector<PII> ve;
    for(int i = 1; i < 2*n; i ++){
        cin >> x[i] >> y[i];
        ve.emplace_back(x[i], y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int cx = x[n-1], cy = y[n-1], LU = 0, RU = 0, LD = 0, RD = 0;
    for(auto [i, j] : ve){
        if(i <= cx){
            if(j <= cy)LD++;
            else LU ++;
        }
        else{
            if(j <= cy)RD++;
            else RU ++;
        }
    }
    if(RD != RU || LU != LD)cout << 0 << '\n';
    else cout << (RD * RD %mod + LD *LD%mod)%mod << '\n';


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
