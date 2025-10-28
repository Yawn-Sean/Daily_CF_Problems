#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e5 + 10;
void solve()
{
    int s;
    cin >> s;
    if(s%2){
        cout << 0 << ' ' << 0 << '\n';
        cout << 1 << ' ' << 0 << '\n';
        cout << 2 << ' ' << 1 << '\n';
        cout << 2 << ' ' << s/2+1 << '\n';
        cout << 1 << ' ' << s/2+1 << '\n';
        cout << 0 << ' ' << s/2 << '\n';
        
    }
    else{
        cout << 0 << ' ' << 0 << '\n';
        cout << 1 << ' ' << 0 << '\n';
        cout << 2 << ' ' << 2 << '\n';
        cout << 2 << ' ' << s/2+1 << '\n';
        cout << 1 << ' ' << s/2+1 << '\n';
        cout << 0 << ' ' << s/2-1 << '\n';
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
