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
    int p;
    cin >> p;
    set<int> ans;
    
    for(int i = 2; i <= N; i ++){
        if(2*(p-1)%(i*(i+1)) == 0){
            if((p-1)%i ==0 && 2*(p-1)%(i+1) == 0)
            ans.insert(i-1);
        }
        if(2*(p-1)%i == 0){
            int v = 2*(p-1)/i;
            int b = sqrt(4*v+1);
            while(b*b < 4*v+1)b++;
            while(b*b > 4*v+1)b--;
            b = (b-1)/2-1;
            if(b > 0 && (p-1)%(b+1) ==0 && 2*(p-1)%(b+2) == 0)
            ans.insert(b);
        }
    }
    cout << ans.size() << '\n';
    for(auto u : ans)cout << u <<' ';
    

}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
