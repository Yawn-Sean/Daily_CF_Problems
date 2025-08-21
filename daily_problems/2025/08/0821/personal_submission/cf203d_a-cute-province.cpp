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
   double a, b,m,vx,vy,vz;
   cin>>a>>b>>m>>vx>>vy>>vz;
   vy *= -1;
   vy = abs(vy);
   double x1 = fmod(m*vz/vy, b), x2 = abs(m*vx/vy)-a/2;
   int y1 = m*vz/vy/b, y2 = (x2)/a;
   if(y1&1)x1 = b -x1;
 
   if(x2>= 0){
    x2 = fmod(x2, a);
   
    if(vx >= 0 && (!(y2&1)))x2=a-x2;
    if(vx < 0 && (y2 & 1))x2 = a-x2;  
   }
   else{
        x2 = m*vx/vy+a/2;
        
   }
   
   
    cout <<fixed << setprecision(10) <<  x2 <<' ' <<  x1<< '\n';


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
