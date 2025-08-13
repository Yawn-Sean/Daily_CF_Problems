#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 


void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = " " +a;
    b = " " + b;
    int ans = 0;
    for(int i = 1; i <= n/2; i ++){
        if(b[i] == b[n+1-i] ){
            if(a[i] != a[n+1-i])
            ans++;
        }
        
        else{
            if(a[i] != b[i] && a[n+1-i] != b[i])ans++;
            if(a[i] != b[n+1-i] && a[n+1-i] != b[n+1-i])ans++;
        }
        
        
    }
    if(n&1 && a[(n+1)/2] != b[(n+1)/2])ans++;
    cout << ans << '\n';
    
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
