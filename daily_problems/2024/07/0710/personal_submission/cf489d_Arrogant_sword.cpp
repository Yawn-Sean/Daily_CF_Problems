
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector cnt(n+1, vector<int>(n+1));
    rep(i, n) {
        for (auto &u: g[i]) {
            for (auto &v: g[u]) {
                if (v != i) {
                    cnt[i][v] ++;
                }
            }
        }
    }

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            ans += (cnt[i][j] - 1) * cnt[i][j] / 2;
        }
    }

    cout << ans << endl;
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