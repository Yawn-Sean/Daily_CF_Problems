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
void solve()
{
   int n;
   cin >> n;
   vector<int> a(n+1);
   for(int i = 1; i <= n; i ++)cin >> a[i];
   for(int i = 1; i < n; i ++){
    if(a[i] >= a[i + 1]){
        cout << a[i] / (a[i+1]-1) << '\n';
        return;
    }
   }
   cout << max(a[n] / (a[n]-a[n-1]), a[n] - a[n-1])<< '\n';
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
