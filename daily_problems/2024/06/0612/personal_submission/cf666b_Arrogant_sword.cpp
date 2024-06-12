
#include<bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    
    vector<int> g[n];
    for (int i = 0; i < m; i ++ ) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        g[u].push_back(v);
    }

    vector d(n, vector<int>(n));
    function<void(int)> bfs = [&](int s)  {
        queue<PII> q;
        q.emplace(s, 0);
        while (!q.empty()) {
            auto [u, dist] = q.front(); q.pop();
            for (int v: g[u]) {
                if (d[s][v] || v == s) continue;
                d[s][v] = dist + 1;
                q.emplace(v, d[s][v]);
            }
        }
    };

    vector mx(n, vector<PII>()), mxr(n, vector<PII>());
    for (int i = 0; i < n; i ++ ) {
        bfs(i);
        d[i][i] = 0;
    }
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (d[i][j] != 0) {
                mx[i].emplace_back(d[i][j], j);
                mxr[j].emplace_back(d[i][j], i);
                
                if (SZ(mx[i]) > 3) {
                    sort(all(mx[i]), [&](PII pa, PII pb) {return pa.first > pb.first;});
                    mx[i].pop_back();   
                }
                if (SZ(mxr[j]) > 3) {
                    sort(all(mxr[j]), [&](PII pa, PII pb) {return pa.first > pb.first;});
                    mxr[j].pop_back();
                }
            }
            
        }
    }
    
    int ans = 0;
    vector<int> res;
    for (int b = 0; b < n; b ++ ) {
        for (int c = 0; c < n; c ++ ) {
            if (d[b][c] == 0) continue;
            vector<PII> as, ds;
            for (int i = 0; i < min(3, SZ(mxr[b])); i ++ ) {
                as.emplace_back(mxr[b][i]);
            }
            for (int i = 0; i < min(3, SZ(mx[c])); i ++ ) {
                ds.emplace_back(mx[c][i]);
            }

            for (auto ta: as) {
                int a = ta.second;
                if (a == c) continue;
                for (auto td: ds) {
                    int dd = td.second;
                    if ( dd != a && dd != b ) {
                        if (d[b][c] + ta.first + td.first > ans) {
                            ans = d[b][c] + ta.first + td.first;
                            res = {a+1, b+1, c+1, dd+1};
                        }
                    }
                }
            }
        }
    }

    print(res);
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