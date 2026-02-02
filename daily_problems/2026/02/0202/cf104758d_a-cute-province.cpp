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
    vector<int> a(n+1), s(n+1), b;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    for(int i = 1; i<= n; i++)s[i] = s[i-1] + a[i];
    int ans = 0;
    vector<int> stk;
    for(int i =1 ; i<= n; i ++){
        while(!stk.empty() && a[stk.back()] < a[i])stk.pop_back();
        int j = i;
        if(!stk.empty())j = stk.back();
        stk.push_back(i);
        ans = max(ans, min(a[i], a[j]) * (i-j-1) - s[i-1] + s[j]);
        //cout << ans <<' ' << j << ' ' << i << '\n';
    }
    stk.clear();
    for(int i = n; i >= 1; i --){
        while(!stk.empty() && a[stk.back()] < a[i])stk.pop_back();
        int j = i;
        if(!stk.empty())j = stk.back();
        stk.push_back(i);
        ans = max(ans, min(a[i], a[j]) * (j-i-1) - s[j-1] + s[i]);
        //cout << ans <<' ' << j << ' ' << i << '\n';
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
