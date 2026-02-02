#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 3e6 + 10;
void solve()
{   
    int n;
    cin >> n;
    vector<int> a(n+1);
   
    for(int i = 1; i <= n; i ++)cin >> a[i];
    map<int, int> cnt, mp, res, p;
    mp[8] = 4;
    mp[15] = 8;
    mp[16] = 15;
    mp[23] = 16;
    mp[42] = 23;
    p[4] = 1;
    p[8] = 2;
    p[15] = 3;
    p[16] = 4;	
    p[23] = 5;
    p[42] = 6;
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(cnt[mp[a[i]]]){
            cnt[mp[a[i]]] --;
            res[p[mp[a[i]]]]--;
            cnt[a[i]] ++;
            res[p[a[i]]] ++;
            continue;
        }
        if(a[i] == 4)
        cnt[a[i]] ++;
    }
	ans = n - res[6] * 6;
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
