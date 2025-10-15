#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e6+10; 
const int mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m+1), ans(n+1);
    vector<PII> ve;
    int sum = 0;
    for(int i = 1; i <=m; i++){
        cin >> a[i];
        ve.emplace_back(min(a[i], n/2), i);
        sum += min(a[i], n/2);
    }
    if(sum < n){
        cout << -1 << '\n';
        return ;
    }
    sort(ve.rbegin(), ve.rend());
    int k = 0;
    for(int i = 1; i <= n; i += 2){
        ans[i] = ve[k].y;
        ve[k].x--;
        if(ve[k].x == 0)k++;
    }
    for(int i =2 ; i <=n ; i+= 2){
        ans[i] = ve[k].y;
        ve[k].x--;
        if(ve[k].x == 0)k++;
    }
   for(int i = 1; i <=n; i++)cout << ans[i] <<' ';
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
