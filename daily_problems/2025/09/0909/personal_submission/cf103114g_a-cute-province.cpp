#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n+1), a(n+1);
    for(int i = 0; i <= 9 ; i ++){
        vector<int> ask;
        for(int j = 1; j <= n;j ++){
            if((j >> i) & 1)ask.emplace_back(j);
        }
        if(ask.size() == 0)break;
        cout<< ask.size() <<' ';
        for(auto u : ask)cout << u << ' ';
        cout <<endl;
        for(int j = 0; j < ask.size(); j ++){
            int x;
            cin >> x;
            w[x] += (1ll << i);
        }
    }
    cout << "! ";
    for(int i = 1; i <=n; i++)a[w[i]] = i;
    for(int i = 1; i <= n; i++)cout << a[i] <<' ';
    cout << endl;
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
