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
    int x1,x2,y1,y2,n,m;
    cin >>n>>m>>x1>>y1>>x2>>y2;
    int dx = abs(x2-x1),dy = abs(y1-y2);
    
    if(dx*2>n || dy*2>m){
        dx=  n - dx,dy =m - dy;
        cout << n*m -2*dx*dy << '\n';
    }
    else cout << 2*dx*dy << '\n';

}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
    cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
