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
   priority_queue<int, vector<int>, greater<int>> pq;
   for(int i = 0 ;i < k; i ++)pq.push(0);
   for(int i = 0 ; i < n; i++){
        int st, p;
        cin >> st >> p;
        int l = pq.top();
        pq.pop();
        pq.push(max(l, st) + p);
        cout << max(l, st) + p << '\n';
   }
   
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
