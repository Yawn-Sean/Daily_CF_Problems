#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 998244353;

void solve()
{
    int n; 
    cin >> n;
     int ans = 0;
    for(int i= 1; i <= n; i++){
        int a, k;
        cin >> k >> a;
       
        ans = max(ans, k + 1);
        while(a > 1){
            a = (a + 3)/4;
            k ++;
        }
        ans = max(ans, k);
        
    } 
    cout << ans << '\n';
    
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流


     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
