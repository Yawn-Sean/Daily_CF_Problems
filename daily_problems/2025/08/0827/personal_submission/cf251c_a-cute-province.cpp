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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    auto check = [&](int x, int y)->bool{
        if(s[x] == s[y] || s[x] == '?' || s[y] == '?')return true;
        else return false;
    };
    for(int j = 1; j <= n; j++){
        for(int i = 0 ;i + j < n;){
            int cnt = 0;
            while(i+j < n && check(i, i + j))i++,cnt++;
            if(cnt >= j)ans = max(ans, j);
            
            i++;
        }
    }
    cout << ans*2 << '\n';


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
