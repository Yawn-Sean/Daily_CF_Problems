#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e3 + 10; 
const int mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> k1, k2;
    vector<int> x(m+1), y(m+1), ans(9);
    vector<vector<int>> X(n+1), Y(n+1);
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i];
        X[y[i]].emplace_back(x[i]);
        Y[x[i]].emplace_back(y[i]);
        k1[x[i] + y[i]].emplace_back(x[i]);
        k2[y[i] - x[i]].emplace_back(x[i]);  
    }
    for(int i = 1; i <= n; i++){
        sort(X[i].begin(), X[i].end());
        sort(Y[i].begin(), Y[i].end());
    }
    for(auto &[_ , v] : k1)sort(v.begin(), v.end());
    for(auto &[_ , v] : k2)sort(v.begin(), v.end());
    for(int i =1 ; i <= m; i ++){
        int w, sum = 0;;
        w = lower_bound(X[y[i]].begin(), X[y[i]].end(), x[i])-X[y[i]].begin();
        if( (w == 0 || w == (int)X[y[i]].size()-1) && X[y[i]].size() > 1)sum++;
        else if((int)X[y[i]].size() > 2) sum += 2;
        w = lower_bound(Y[x[i]].begin(), Y[x[i]].end(),  y[i])-Y[x[i]].begin();
        if( (w == 0 || w == (int)Y[x[i]].size()-1) && Y[x[i]].size() > 1)sum++;
        else if((int)Y[x[i]].size() > 2)sum += 2;
        w = lower_bound(k1[x[i] + y[i]].begin(), k1[x[i] + y[i]].end(), x[i]) - k1[x[i] + y[i]].begin();
        if( (w == 0 || w == (int)k1[x[i] + y[i]].size()-1) && k1[x[i] + y[i]].size() > 1)sum++;
        else if((int)k1[x[i] + y[i]].size() > 2)sum += 2;
        w = lower_bound(k2[y[i] - x[i]].begin(), k2[y[i] - x[i]].end(), x[i]) - k2[y[i] - x[i]].begin();
        if( (w == 0 || w == (int)k2[y[i] - x[i]].size()-1) && k2[y[i] - x[i]].size() > 1)sum++;
        else if((int)k2[y[i] - x[i]].size() > 2)sum += 2;
        ans[sum] ++;
    }
    for(int i = 0 ; i <= 8; i ++)cout << ans[i] <<' ';
   
    
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
