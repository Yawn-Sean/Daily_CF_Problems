
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> g[n+1], ans(n+1, 1);
    for (int i = 2, fa; i <= n; i ++ ) {
        cin >> fa;
        g[fa].push_back(i);
        ans[fa] = 0;
    }
    function<void(int)> dfs = [&](int u) {
        for (int v: g[u]) {
            dfs(v);
            ans[u] += ans[v];
        }
    };

    dfs(1);
    
    sort(all(ans));
    for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
    cout << endl;

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}