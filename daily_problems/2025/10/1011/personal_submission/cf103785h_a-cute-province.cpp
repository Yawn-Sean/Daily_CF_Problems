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

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n+1), ans;
    for(int i = 1; i <= n; i++)cin >> a[i];
    
    while(a.size() > 1){
        int ok = 0;
        for(int i = a.size()-1; i >= 1; i --){
            if(a[i] == i){
                ok = 1;
                ans.emplace_back(i);
                a.erase(a.begin()+i);
                break;
            }
        }
        if(ok == 0){
            cout << "NO" << '\n';
            return ;
        }
    }
    cout << "YES" << '\n';
    for(int i = ans.size()-1; i >= 0; i --)cout << ans[i] <<' ';
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
