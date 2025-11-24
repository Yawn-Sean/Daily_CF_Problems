#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;

void solve()
{   
   int n;
   cin >> n;
   vector<int> a(n);
   if(n <= 2){  
        int x, y, sum = 0;
        cin >> x >> y;
        sum = x + y;
        if(sum == 0){
            cout << 0<< '\n';
            return ;
        }
        while(x >= 2 || y >= 2){
            x += y/2;
            y %= 2;
            y += x/2;
            x %= 2;
        }
        if((x+y)>1)cout << sum-2 << '\n';
        else cout << sum-1 << '\n';
   }
   else{
    int cnt =0, sum = 0, cnt0 = 0;
    for(auto &x  :a){
        cin >> x;
        sum += x;
        if(x == 1)cnt++;
        if(x == 0)cnt0 ++;
    }
    if(cnt == sum)cout << "0\n";
    else{
        if(cnt0 == n-1){
            if(sum <= 3)cout << 1<<'\n';
            else cout <<sum-1 << '\n';
        }
        else{
            cout << sum-1 << '\n';
        }
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
    //t = 1;
    cin >> t;    
    while (t--)
    {
        solve();
    }
    return 0;
}
