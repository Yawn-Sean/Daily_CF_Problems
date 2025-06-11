
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
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
    vector<int> p(n+1), c(n+1), g[n+1];
    for (int i = 1; i <= n; i ++ ) {
        int fa;
        cin >> fa;
        g[fa].push_back(i);
        cin >> c[i];
    }

    function<vector<int>(int)> dfs = [&](int u) -> vector<int> {
        vector<int> tmp;
        for (auto v: g[u]) {
            for (auto x: dfs(v)) {
                tmp.push_back(x);
            }
        }

        if (SZ(tmp) < c[u]) {
            cout << "NO" << endl;
            exit(0);
        }

        tmp.insert(tmp.begin() + c[u], u);
        return tmp;
    };

    auto res = dfs(g[0][0]);
    vector<int> ans(n+1);
    for (int i = 0; i < n; i ++ ) {
        ans[res[i]] = i + 1;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i ++ ) {
        cout << ans[i] << ' ';
    }
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