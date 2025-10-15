#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll inf = 1e15 + 7;
const int N = 1e6 + 7;
struct edge {int u, v, nxt, w, id;}e[N<<2];
struct node {int s, t, w;} rd[N];
 
int inq[N], disc[N<<1], dis[N], dcnt, head[N], ecnt, n, L, ans[N], cnt, pre[N];
 
typedef pair <int, int> pii;
#define MK(a,b) make_pair(a, b)
 
priority_queue <pii, vector <pii>, greater<pii> > q;
 
void adde (int u, int v, int w, int id) {
    e[ecnt].u = u;
    e[ecnt].v = v;
    e[ecnt].w = w;
    e[ecnt].id = id;
    e[ecnt].nxt = head[u];
    head[u] = ecnt++;
}
 
void Dijkstra () {
    memset (dis, 127, sizeof dis);
    pre[1] = -1;
    dis[1] = 0;
    q.push(MK(0, 1));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop(); inq[u] = 0;
        for (int it = head[u]; it != -1; it = e[it].nxt) {
            int v = e[it].v;
            if (dis[v] > dis[u] + e[it].w) {
                dis[v] = dis[u] + e[it].w;
                pre[v] = it;
                q.push(MK(dis[v], v));
            }
        }
    }
    for (int it = pre[dcnt]; it != -1; it = pre[e[it].u])
        if (e[it].id != -1) ans[++cnt] = e[it].id;
}
 
int main () {
    scanf ("%d%d", &n, &L);
    memset (head, -1, sizeof head);
    disc[++dcnt] = 0;
    disc[++dcnt] = L;
    for (int i = 1; i <= n ; ++i) {
        int x, d, t, p;
        scanf ("%d%d%d%d", &x, &d, &t, &p);
        rd[i].s = x - p;
        rd[i].t = x + d;
        rd[i].w = t + p;
        if (x - p < 0 || x + d > L) continue;
        disc[++dcnt] = x - p;
        disc[++dcnt] = x + d;
    }
    sort (disc + 1, disc + 1 + dcnt);
    dcnt = unique (disc + 1, disc + 1 + dcnt) - disc - 1;
    for (int i = 1; i <= n; ++i) {
        if (rd[i].t > L || rd[i].s < 0) continue;
        int s = lower_bound (disc + 1, disc + 1 + dcnt, rd[i].s) - disc;
        int t = lower_bound (disc + 1, disc + 1 + dcnt, rd[i].t) - disc;
        adde (s, t, rd[i].w, i);
    }
    for (int i = 2; i <= dcnt; ++i) {
        int s = i - 1, t = i, w = disc[t] - disc[s];
        adde (s, t, w, -1);
        adde (t, s, w, -1);
    }
    Dijkstra();
    cout << dis[dcnt] << endl << cnt << endl;
    for (int i = cnt; i >= 1; --i) printf ("%d ", ans[i]);
    return 0;
}
