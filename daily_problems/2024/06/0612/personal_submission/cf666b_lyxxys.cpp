#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9, mod = 998244353, N = 3050;
vector <int> g[N];
int dis[N][N];
int dot[N][3], pot[N][3];
bool inq[N];

// 预处理dot，既c到哪个点 的 前三大值
void bfs(int ori){
    queue <int> que;
    que.push(ori);
    inq[ori] = true;
    dis[ori][ori] = 0;
    int dis1, dis2, dis3;
    dis1 = dis2 = dis3 = 0;
    while (que.size()){
        int t = que.front();
        que.pop();
        inq[t] = false;
        for (auto &x : g[t]){
            if (dis[ori][x] <= dis[ori][t]+1) continue;
            dis[ori][x] = dis[ori][t] + 1;
            if (!inq[x]) que.push(x), inq[x] = true;
            int dist = dis[ori][x];
            auto &p = dot[ori];
            if (dist > dis1){
                dis3 = dis2, dis2 = dis1, dis1 = dist;
                p[2] = p[1], p[1] = p[0], p[0] = x;
            } else if (dist > dis2){
                dis3 = dis2, dis2 = dist;
                p[2] = p[1], p[1] = x;
            } else if (dist > dis3){
                dis3 = dist, p[2] = x;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j <= n; ++ j)
            dis[i][j] = INF;

    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; ++ i) bfs(i);
    // a, b, c, d 注意是预处理哪个点到b 和 c到哪个点 的三个最大值
    //预处理pot，既哪个点到 b 的前三大值
    for (int i = 1; i <= n; ++ i){
        int dis1, dis2, dis3;
        dis1 = dis2 = dis3 = 0;
        for (int j = 1; j <= n; ++ j){
            if (i == j) continue;
            int dist = dis[j][i];
            if (dist == INF) continue;
            auto &p = pot[i];
            if (dist > dis1){
                dis3 = dis2, dis2 = dis1, dis1 = dist;
                p[2] = p[1], p[1] = p[0], p[0] = j;
            } else if (dist > dis2){
                dis3 = dis2, dis2 = dist;
                p[2] = p[1], p[1] = j;
            } else if (dist > dis3){
                dis3 = dist, p[2] = j;
            }
        }
    }

    array <int,4> res = {0};
    int dist = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i == j) continue;
            if (dis[i][j] == INF) continue;
            int x, y, disxy = 0;
            bool flg = true;
            for (int di = 0; di < 3; ++ di){
                for (int dj = 0; dj < 3; ++ dj){
                    int a = pot[i][di], b = dot[j][dj];
                    if (a == b) continue;
                    if (a == i || a == j) continue;
                    if (b == i || b == j) continue;
                    if (dis[a][i] == INF || dis[j][b] == INF) continue;
                    flg = false;
                    if (dis[a][i]+dis[j][b] > disxy) x = a, y = b, disxy = dis[a][i] + dis[j][b];
                }
            }
            if (flg) continue;
            if (disxy+dis[i][j] > dist){
                dist = disxy+dis[i][j];
                res = {x, i, j, y};
            }
        }
    }
    for (int i = 0; i < 4; ++ i) cout << res[i] << "\n "[i < 3];
}
