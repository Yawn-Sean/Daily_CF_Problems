
#include<bits/stdc++.h>
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
// 链表模拟合并
const int N = 2e5 + 10;
vector<int> p(N), head(N), nxt(N), tail(N);

int find(int x) {
    return ((p[x] == x) ? x : p[x] = find(p[x]));
}

// 把v所在的连通块接到u的尾部。
void merge(int u, int v) {
    u = find(u); v = find(v);
    nxt[tail[u]] = head[v]; tail[u] = tail[v];
    p[v] = u;
}

void solve(int _) 
{
    int n;
    cin >> n;
    rep(i, n) {
        p[i] = head[i] = tail[i] = i;
    }

    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    int s = head[find(1)];
    rep(i, n) {
        cout << s << ' ';
        s = nxt[s];
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