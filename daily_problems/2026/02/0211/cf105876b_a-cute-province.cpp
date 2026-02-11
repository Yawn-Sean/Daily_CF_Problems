#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
int v[4] = {1, 2, 4, 3};
void solve()
{
    int n;
    cin >> n;
    int k = n/4;
    int j= 0;
    if(n % 4 == 3){
        cout << -1 << '\n';
        return; 
    }
    for(int i = 1; i <= k+1; i ++){
        for(; j < min(n, i*4); j ++)cout <<4*(i-1) + v[j%4] <<' ';
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
