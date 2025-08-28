#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
/*  
    起点到终点要走奇数次,起点和终点可以向外延申偶数次
*/
void solve()
{
   int n;;
   cin >> n;
   vector<int> a(n+1), sum1(n+1), sum2(n+1), dpl(n+1), dpr(n+1);
   for(int i = 1; i <n; i ++){
   	cin >> a[i];
   	sum1[i] = sum1[i-1] + a[i] - ((a[i]&1)^1);
	sum2[i] = sum2[i-1] + a[i] - ((a[i]&1)^0); 
   }
   int p = 0;
   for(int i = 1; i < n; i++){
   		if(a[i] == 1){
   			p = i;	
		}
		dpl[i+1] = sum2[i] - sum2[p];
   }
   p = n-1;
   for(int i = n-1; i >=1; i--){
   		if(a[i] == 1){
   			p = i;	
		}
		dpr[i] = sum2[p] - sum2[i-1];
   }
   int ans = 0, ma = 0;
   for(int i = 1; i <=n; i ++){
   	ma = max(ma, dpl[i]-sum1[i-1]);
   		ans = max(ans, sum1[i-1] + ma + dpr[i]);
   }
   cout << ans << '\n';
   
}
signed cute_prov0nce()
{
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
