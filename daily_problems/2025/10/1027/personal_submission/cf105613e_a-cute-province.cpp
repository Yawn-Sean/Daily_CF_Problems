#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 1e6 + 10;
void solve()
{
    int n, k;
    cin >> n >> k;
    if(k > n* (n-1)/2){
        cout << -1 << '\n';
    }
    else{
        int p = ceil((1+sqrt(1+8*k))/2);
        if(k == p*(p-1)/2){
            for(int i = 1; i <= p; i ++){
                cout << 2 << ' ';
            }
        }
        else{
            int last = p*(p-1)/2 - k;
            for(int i = 1; i <= last; i ++){
                cout << 4 <<' ';
            }
            for(int i = last+1; i <= p-1; i++){
                cout <<2  <<' ';
            }
            cout << 6 <<' ';
        }
        int cnt = 0;
        for(int i = 1000000-1; cnt < n-p; i -=2){
            cout << i <<' ';
            cnt++;
        }
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
