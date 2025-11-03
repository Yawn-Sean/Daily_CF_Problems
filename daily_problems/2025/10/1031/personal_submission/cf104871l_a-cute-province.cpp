#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 3e4 + 10;
int cnt[N][20];
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n+1);
    for(int i = 0; i < 15; i ++){
        cout << "QUERY ";
        for(int j = 1; j <= n;j  ++){
            if((j >> i)&1)cout << 1;
            else cout << 0;
        }
        cout << endl;
        for(int j = 1; j <= n; j ++){
            cin >> cnt[j][i];
        }
    }
    queue<int> q;
    cout << "QUERY ";
    for(int i = 1; i <= n; i ++)cout << 1;
    cout << endl;
    for(int i = 1; i <=n; i ++){
        cin >> d[i];
    }
    for(int i = 1; i <= n; i ++){
        if(d[i] == 1)q.push(i);
    }
    vector<PII> ans;
    while(!q.empty()){
        auto s = q.front(); q.pop();
        int u = 0;
        for(int i = 0 ;i < 15; i ++)
        u += (cnt[s][i]<< i);
        ans.emplace_back(u, s);
        for(int i = 0; i < 15;i  ++)
        cnt[u][i] -= ((s>>i)&1); 
        if(--d[u] == 1)q.push(u);
    }
    cout << "ANSWER" <<endl;
    for(auto [u, v] : ans)cout << u << ' ' << v << endl;
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
