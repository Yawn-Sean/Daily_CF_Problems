#include<bits/stdc++.h>

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}


//////////////////////////////////////////////////

void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    vector<int> color(n+1, -1), vis(n+1);
    
    for (int i = 0; i < m; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);
            while (q.size()) {
                //cout << color[2] << endl;
                int u = q.front(); q.pop();
                for (int v: g[u]) {
                    if (color[v] == -1)  {
                        
                        color[v] = 1 - color[u];
                        
                        q.push(v);
                    } else {
                        if (color[v] != 1 - color[u]) {
                            
                            cout << -1 << endl;
                            return;
                        }
                    }
                    
                }
            }
        }
    }
    
    vector<int> ans1, ans2;
    for (int i = 1; i <= n; i ++ ) {
        if (color[i] == 0) ans1.pb(i);
        else ans2.pb(i);
    }
    
    cout << ans1.size() << endl;
    print(ans1);
    cout << ans2.size() << endl;
    print(ans2);
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}
