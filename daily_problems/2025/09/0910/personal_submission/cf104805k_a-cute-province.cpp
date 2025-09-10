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
int vis[20];
void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    set<int> st;
    for(int i = 0; i < n; i++)cin >> x[i], vis[x[i] + 1]= 1;
    int ans = 0;
    auto dfs = [&](auto &dfs, int sum)->void{ 
        for(int i = 2; i <= 16; i ++){
            if(vis[i]){
                if(sum * i <= l + 1 && st.find(sum * i) == st.end()){
                    st.insert(sum * i);
                    dfs(dfs, sum * i);
                }
            }
        }
    };
    dfs(dfs, 1);
    cout << st.size() << '\n';
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
