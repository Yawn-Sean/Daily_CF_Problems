#include <bits/stdc++.h>
#define x first
#define y second
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
   vector<int> a(n);
   vector<int> k(n), x(n), y(n), m(n), cnt(n);
   vector<vector<int>> tmp(n);
   int ans = 0, sum = 0, last = -1;
   for(int i = 0;i < n;i ++){
    cin >> k[i]>>a[i] >> x[i] >> y[i] >> m[i];  
    sum += k[i];
   }
   cnt = a;
   for(int i = 0; i < n; i++){
    int num = 1;
    for(int j = 1; j < k[i]; j ++){ 
        int ed = ((i64)a[i] * x[i] + y[i])%m[i];
        if(ed < a[i]){
            tmp[i].emplace_back(num);
            num = 0;
        }
        num++;
        a[i] = ed;
    }
    tmp[i].emplace_back(num);
    ans = max(ans, (int)tmp[i].size());
   }
   cout << ans-1 << '\n';
   if(sum <= 200000){
    
    for(int j = 0; j < ans; j ++){
        vector<PII> ve;
        for(int i = 0; i < n; i++){
            if(tmp[i].size()-1 < j)continue;
            int p = tmp[i][j];
            for(int o = 0; o < p; o ++){
                ve.emplace_back(cnt[i], i);
                cnt[i] = ((i64)cnt[i] * x[i] + y[i]) %m[i];
            }       
    }
    sort(ve.begin(), ve.end());
    for(auto [u, v] : ve)cout << u <<' ' << v + 1 << '\n';
   }
   
}
}
int cute_prov0nce()
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
