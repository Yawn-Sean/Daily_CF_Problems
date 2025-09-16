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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <=n; i ++)cin >> a[i];
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        else{
            int x;
            cin >> x;
            vector<int> ans;
            for(int i = 1 ;i <= 1000; i ++){
                if(i+x <= n &&  i* i * i >= a[x+i])ans.emplace_back(x+i);
                if(x-i >= 1 &&  i * i * i >= a[x-i])ans.emplace_back(x-i);
            }
            if(ans.size() == 0)cout<<-1<<'\n';
            else{
                cout << ans[0] << ' ';
                cout << '\n';
            }
 
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
