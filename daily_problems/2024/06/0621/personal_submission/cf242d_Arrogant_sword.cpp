
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int>& vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
// 如果当前状态有一个点a[i] = b[i]那就按它，且之后的操作必然不会使得b[i]变小。所以必然有解。
// 用队列模拟上述过程即可。
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> a(n+1), b(n+1);
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if (!a[i]) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        b[u] ++;
        for (int v: g[u]) {
            b[v] ++;
            if (b[v] == a[v] ) {
                q.push(v);
            }
        }
    }

    cout << SZ(ans) << endl;
    print(ans);
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