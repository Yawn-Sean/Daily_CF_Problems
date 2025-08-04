#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 998244353;
/*
    问题的目标，等价于寻找一个射线序列，当它按入口位置排序后，其对应的出口位置序列构成一个严格递减的序列。我们想让这个序列尽可能地长
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n+1), y(n+1), id(n+1), a(n+1);
    for(int i =1 ; i<= n; i ++)cin >> x[i], id[x[i]] = i;
    for(int i =1 ; i<= n; i ++)cin >> y[i], a[i] = id[y[i]];
    vector<int> ends(n);int cnt = 0;
    for(int i = 1; i <= n; i ++){
        int w = upper_bound(ends.begin(), ends.begin() + cnt, a[i], greater<int>()) - ends.begin();
        if(w != cnt)ends[w] = a[i];
        else ends[cnt++] = a[i];
    }
    cout << cnt << '\n';
    
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
