#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;
const int N = 1e6 + 10;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    while(q--){
        int op, k, x, y;
        cin >> op;
        if(op == 1){
            cin >> k;
            auto w = lower_bound(a.begin(), a.end(), k) - a.begin();
            if(w == a.size())a.emplace_back(k);
            else a[w] = k;
        }
        else{
            cin >> x >> y;
            cout << upper_bound(a.begin(), a.end(), y) - lower_bound(a.begin(), a.end(), x) << '\n';
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
