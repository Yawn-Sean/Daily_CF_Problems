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
const int N = 2e5 + 10;

void solve()
{   
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    for(int i = 1; i <= n; i ++)cin >> b[i];
    c.emplace_back(0);
    for(int i =1 ; i <= n; i++){
        if(a[i] >= b[i]){
            c.emplace_back(a[i]);
            c.emplace_back(b[i]);
        }  
        else{
            c.emplace_back(b[i]);
            c.emplace_back(a[i]);
        }
    }
    //for(auto s : c)cout << s << ' ';
    auto LIS = [&](vector<int> v)->int{
        vector<int> ends(2*n+1);
        int cnt = 0;
        for(int i = 1; i <= 2*n; i ++){
            auto w = lower_bound(ends.begin(), ends.begin()+cnt+1, v[i]) - ends.begin();
            if(w > cnt){
                ends[++cnt] = v[i];
            }
            else ends[w] = v[i];
        }
        return cnt;
    };
    
    cout << LIS(c) << '\n';
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
