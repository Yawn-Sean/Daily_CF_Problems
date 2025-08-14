#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e2; 
const int mod = 1e9 + 7;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v;
    
    int money = 1, sum = 1;
    v.emplace_back(1);
    if(a && b == 0)v.emplace_back(1), sum++;
    while(money <= 50000 && (a || b)){
        if(b)money = sum+1, b--;
        else money ++, a--;
        v.emplace_back(money);
        if(v.size() == n)break;
        sum += money;
    }
    if(a || b || v.size() > n)cout << -1 << '\n';
    else{
        for(auto u : v)cout <<u <<' ';
        for(int i = 1; i <= n-v.size(); i ++)cout << 1 <<' ';
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
