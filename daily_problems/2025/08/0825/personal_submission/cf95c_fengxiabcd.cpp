// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define vi vector<int>
#define vpii  vector<pii>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define pqi priority_queue<int,vector<int>, greater<int>>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
const int N = 1e3 + 5;
vpii g[N];
pii a[N];
int dis[N][N];
int val[N];
int n,m;
void dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dis[s][i] = INF;
    }
    dis[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(mp(0, s));
    while (!q.empty()) {
        pii t = q.top();
        q.pop();
        int u = t.s;
        int d = t.f;
        if (d > dis[s][u]) continue;
        for (auto v : g[u]) {
            int to = v.f;
            int len = v.s;
            if (dis[s][to] > dis[s][u] + len) {
                dis[s][to] = dis[s][u] + len;
                q.push(mp(dis[s][to], to));
            }
        }
    }
}
int dj(int s,int t){
    fill(val,val+n+1,INF);
    pqpii q;
    q.push(mp(0,s));
    while(!q.empty()){
        pii v = q.top();
        q.pop();
        int u = v.s;
        int d = v.f;
        if(u == t)return d;
        if(d > val[u])continue;
        for(int i=1;i<=n;i++){
            if(a[u].f>=dis[u][i]){
                if(val[i] > d + a[u].s){
                    val[i] = d + a[u].s;
                    q.push(mp(val[i],i));
                }
            }
        }

    }
    return -1;
}
void slove(){
    cin >> n>>m;
    int s,t;
    cin >> s >> t;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
    }
    for(int i = 1; i <= n; i++)dijkstra(i);
    cout << dj(s,t) << endl;
}
signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("test.in", "w", stdout);
    // cout<<fixed<<setprecision(3);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)slove();
    return 0;
}
