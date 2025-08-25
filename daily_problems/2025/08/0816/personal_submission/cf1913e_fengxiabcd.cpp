// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
struct MCFGraph {
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<i64> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<i64>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            i64 d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                int v = e[i].v;
                int c = e[i].c;
                int f = e[i].f;
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<i64>::max();
    }
    MCFGraph(int n) : n(n), g(n) {}
    void add(int u, int v, int c, int f) { // 最大流
    g[u].push_back(e.size());
    e.emplace_back(v, c, f);
    g[v].push_back(e.size());
    e.emplace_back(u, 0, -f);
}
    std::pair<int, i64> flow(int s, int t) {
        int flow = 0;
        i64 cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += i64(aug) * h[t];
        }
        return std::make_pair(flow, cost);
    }
};
void slove(){
    int n, m;
    cin >> n >> m;
    MCFGraph mcmf(n * m + n + m + 10);
    vector<int> a(n), b(m), a1(n), b1(m);
    for(int i=0;i<n;i++)a[i]=n*m+i;
    for(int i=0;i<m;i++)b[i]=n*m+n+i;
    int st=n*m+n+m,en=n*m+n+m+1;
    int tot=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            if (x == 1){
                mcmf.add(a[i], i * m + j, 1, 0);
                mcmf.add(i * m + j, b[j], 1, 0);
                tot++;
            }
            else{
                mcmf.add(a[i], i * m + j, 1, 2);
                mcmf.add(i * m + j, b[j], 1, 0);
            }
        }
    }
    for(int i=0;i<n;i++)cin>>a1[i];
    for(int i=0;i<m;i++)cin>>b1[i];
    if(accumulate(all(a1),0ll)!=accumulate(all(b1),0ll)){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n;i++)mcmf.add(st,a[i],a1[i],0);
    for(int i=0;i<m;i++)mcmf.add(b[i],en,b1[i],0);
    pii ans=mcmf.flow(st,en);
    //cout<<ans.f<<endl;
    if(ans.f!=accumulate(all(a1),0ll)){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.s-accumulate(all(a1),0ll)+tot<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)slove();
    return 0;
}
