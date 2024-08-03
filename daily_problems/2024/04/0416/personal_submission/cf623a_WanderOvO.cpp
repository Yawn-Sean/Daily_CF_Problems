/*
只有一种元素：完全图
只有 ab 或者 bc：完全图
只有 ac：两个分支，分别是完全图
同时有 abc，ab 组成一波完全图，bc 组成一波完全图
b 的度一定是 n - 1，a 的度是 cnta + cntb - 1，c 的度是 cntb + cntc - 1
所有 b 组成一个完全图，从任意一个 b 开始走，走到一个度不是 n - 1 的点，就是 a 或者 c
但这个思路写起来非常屎山

羊：如果两个点没有连边，那肯定是 a 和 c
我们把原来的边都断掉，原来没有的边连上，看看能否弄成二分图
如果是二分图，且只有一个分支，那么就是对的，
*/

int T;
int n, m;
int w[N][N], color[N], d[N];
bool vis[N];
bool ok;

void dfs(int u, int c) {
    vis[u] = true;
    color[u] = c;
    for (int i = 1; i <= n; i++) {
        if (u != i && w[u][i] != 0) {
            if (!vis[i]) {
                dfs(i, c ^ 2);
            } 
        }
    }
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = 1;
        }
        w[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        w[u][v] = 0;
        w[v][u] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] == 1) {
                d[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 1;
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && d[i] != 0) {
            dfs(i, 0);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int t = ((color[i] ^ color[j]) == 2) ? 1 : 0;
            if (w[i][j] != t) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        char s = color[i] + 'a';
        cout << s;
    }
}