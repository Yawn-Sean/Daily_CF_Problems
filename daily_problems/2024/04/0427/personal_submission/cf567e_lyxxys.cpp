#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Pli = pair<ll, int>;
const int N = 100050, p = 998244353;
int h[N], rh[N], e[2*N], ne[2*N], w[2*N], idx;
ll dist[N][2], fcnt[N][2];
int n, m, S, T;
 
void add(int h[], int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
bool st[N];
void dijkstra(){
    priority_queue <Pli, vector<Pli>, greater<Pli>> heap;
    dist[S][0] = 0, fcnt[S][0] = 1;
    heap.push({0, S});
    while (heap.size()){
        auto t = heap.top();
        int u = t.second;
        heap.pop();
        if (t.first > dist[u][0]) continue;
        for (int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            ll dis = dist[u][0]+w[i];
            if (dist[j][0] > dis){
                dist[j][0] = dis, fcnt[j][0] = fcnt[u][0];
                heap.push({dist[j][0], j});
            }
            else if (dist[j][0] == dis) fcnt[j][0] = (fcnt[j][0] + fcnt[u][0]) % p;
        }
    }
}
void rdijkstra(){
    priority_queue <Pli, vector<Pli>, greater<Pli>> heap;
    dist[T][1] = 0, fcnt[T][1] = 1;
    heap.push({0, T});
    while (heap.size()){
        auto t = heap.top();
        int u = t.second;
        heap.pop();
        if (t.first > dist[u][1]) continue;
        for (int i = rh[u]; ~i; i = ne[i]){
            int j = e[i];
            ll dis = dist[u][1]+w[i];
            if (dist[j][1] > dis){
                dist[j][1] = dis, fcnt[j][1] = fcnt[u][1];
                heap.push({dist[j][1], j});
            }
            else if (dist[j][1] == dis) fcnt[j][1] = (fcnt[j][1] + fcnt[u][1]) % p;
        }
    }
}
bool check(int u, int v, int wei){
    if (dist[u][0] + dist[v][1] + wei != dist[T][0]) return false;
    if (fcnt[u][0] * fcnt[v][1]%p != fcnt[T][0]) return false;
    return true;
}
struct Edge{
    int a, b, c;
};
void solve(){
    memset(h, -1, sizeof h), memset(rh, -1, sizeof rh), idx = 0;
    cin >> n >> m >> S >> T;
    vector <Edge> edge;
    for (int i = 1; i <= m; ++ i){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
        add(h, a, b, c), add(rh, b, a, c);
    }
    memset(dist, 0x3f, sizeof dist);
    dijkstra();
    rdijkstra();
 
    for (auto &contain: edge){
        int u = contain.a, v = contain.b, wei = contain.c;
        if (!check(u, v, wei)){
            ll diff = dist[T][0] - (dist[u][0] + dist[v][1]);
            if (diff <= 1 || wei-diff < 0) cout << "NO\n";
            else cout << "CAN " << (wei-diff+1) << "\n";
        }
        else cout << "YES\n";
    }
}
