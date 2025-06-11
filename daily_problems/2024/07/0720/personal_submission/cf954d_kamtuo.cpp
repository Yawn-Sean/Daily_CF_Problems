/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-20 11:02 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 2234;

int ne[N], idx = 1, h[N], d[N], w[N];
int dist[N], dist2[N];
bool path[N][N];
int n, m, s, t;
bool st[N], st2[N];

struct Node {
    int u;
    int w;
    bool operator < (const Node & now) const {
        return w > now.w;
    };
};

void add(int u, int v) {
    ne[idx] = h[u];
    d[idx] = v;
    w[idx] = 1;
    h[u] = idx ++;
}

int main() {
    cin >> n >> m >> s >> t;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        path[u][v] = path[v][u] = true;
        add(u, v);
        add(v, u);
    }
    dist[t] = 0;
    priority_queue<Node> pq;
    pq.push({t, 0});
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (st[now.u]) continue;
        st[now.u] = true;
        for (int i = h[now.u]; i; i = ne[i]) {
            if (dist[d[i]] > now.w + 1) {
                dist[d[i]] = now.w + 1;
                pq.push({d[i], now.w + 1});
            }
        }
    }
    memset(dist2, 0x3f, sizeof dist2);
    pq.push({s, 0});
    dist2[s] = 0;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (st2[now.u]) continue;
        st2[now.u] = true;
        for (int i = h[now.u]; i; i = ne[i]) {
            if (dist2[d[i]] > now.w + 1) {
                dist2[d[i]] = now.w + 1;
                pq.push({d[i], now.w + 1});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (path[i][j]) continue;
            if (min(dist2[i] + 1 + dist[j], dist[i] + 1 + dist2[j])>= dist[s]) {
                ans ++;
            }
            // if ()
        }
    }
    cout << ans << endl;
    return 0;
}

/*

*/
