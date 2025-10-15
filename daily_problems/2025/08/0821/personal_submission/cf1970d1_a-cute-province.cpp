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
string s[3] = {"X", "OXX", "XOXO"};
void solve()
{
   map<int, PII> ans;
   ans[2] = {1, 1};
   ans[8] = {1, 2};
   ans[11] = {1, 3};
   ans[7] = {2, 1};
   ans[14] = {2, 2};
   ans[20] = {2, 3};
   ans[9] = {3, 1};
   ans[21] = {3, 2};
   ans[15] = {3, 3};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cout << s[i] <<endl;
    int q;
    cin >> q;
    while(q--){
        int c;
        cin >> c;
        cout << ans[c].x <<' ' << ans[c].y <<endl;
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
