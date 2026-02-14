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
mt19937_64 rnd(19890604);
void solve()
{
   int n;
   string ans;
   cin >> n;
   while(1){
    for(int i = 1; i < n; i ++){
        cout << i << ' ' << i+1 << endl;
        cin >> ans;
        if(ans == "WIN")exit(0);
    }
    for(int i = n; i > 1; i --){
        cout << i-1 << ' ' << i << endl;
        cin >> ans;
        if(ans == "WIN")exit(0);
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
    // >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
