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
const int N = 5000 + 10;
int v[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solve()
{   
    int n;
    cin >> n;
    if(n == 6){
        cout << 0 << '\n';
        return ;
    }
    int d = ceil(n * 1.0/7);
    for(int i = 1; i <= d; i ++){
        for(int j = (i == 1); j <= 9; j ++){
        	if(n < v[j])continue;
            if(n - v[j] <= (d-i) * 7){
                cout << j;
                n -= v[j];
                break;
            }
        }
    }
    cout << '\n';
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
