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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   map<int, int> nums;
   for(auto &x : a)cin >> x, nums[x]++;
   sort(a.begin(), a.end());
   k--;
   int ed1 = a[k/n], ed2;
    for(int i = 0; i < n; i ++){
        if(a[i] == ed1){
            k -= i*n;
            break;
        }
    }
    k++;
    for(int i = 0 ; i < n; i++){
        k-=nums[ed1];
        if(k <=0){
            ed2 = a[i];
            break;
        }
    }
   cout << ed1 <<' ' << ed2 << '\n';
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
