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

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n+1);
   for(int i =1;  i<= n; i++)cin >> a[i];
   cout << "YES" << '\n';
   for(int i =1 ; i <=n ; i++)cout << i <<' ' << i << '\n';
    for(int i =1 ;i <= n; i++){
        if(i + a[i]/2 <= n)cout <<i + a[i]/2 << ' ';
        else cout << i - a[i]/2 << ' ';
    }

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
