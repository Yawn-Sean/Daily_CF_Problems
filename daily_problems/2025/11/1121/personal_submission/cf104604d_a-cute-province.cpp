#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;

void solve()
{
    int a, b;
    cin >> a >> b;
    if(a > b)swap(a, b);
    if(a == b){
        if (a %2 == 0)
        cout << "SI\n"; 
        else cout << "NO\n";
    }
    else{
        if(a%(b-a) == 0){
            for(int x = 2; x <= 4; x++){
                if(b%x || a == b/x)continue;
                if(b % (a-b/x) == 0){
                    cout << "SI\n";
                    return;
                }
            }
            cout << "NO\n";
        }
        else cout << "NO\n";
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
