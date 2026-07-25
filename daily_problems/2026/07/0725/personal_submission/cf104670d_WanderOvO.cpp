/*
假如某一步操作是 op，说明一定不是按照 op 这个方向走的
因为题目说了改成别的了
然后题目说了，那个位置的最短路长度就是序列操作的长度，所以这意味着肯定不能走回头路
一个暴力的方案是，维护走 i 步后所有可能的位置
然后暴力去看第 i + 1 步走完之后新的位置在哪儿
需要标记所有已经走过的位置
如果扩展的时候，只要遇到了走过的位置，就说明不是最短路了，可以抛弃掉这种情况
这似乎意味着，我们每个点其实至多只会被标记 1 次？
这其实几乎就是一个 BFS 的复杂度
所以并非暴力，模拟的复杂度似乎是正确的？
好像不完全对，会 WA 8
我们最后确实找到了一堆候选点
但是，这些点未必真的是最短路走到的
我们要再做一遍 BFS，检查一下是否真的最短路是 len(op)
*/ 

const int N = 1010;

int n, m;
string op, grid[N];
int vis[N][N];
int dist[N][N];
// E W S N
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int get_ban(char ch) {
    if (ch == 'E') {
        return 0;
    } else if (ch == 'W') {
        return 1;
    } else if (ch == 'S') {
        return 2;
    } else {
        return 3;
    }
}

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && (grid[x][y] == '.') && !vis[x][y];
}

void calc(int sx, int sy) {
    queue<PII> q;
    dist[sx][sy] = 0;
    memset(vis, 0, sizeof vis);
    q.push({sx, sy});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = dx[i] + x, yy = dy[i] + y;
            if (valid(xx, yy)) {
                dist[xx][yy] = dist[x][y] + 1;
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cin >> op;

    queue<PII> q[2];
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } 
        }
    }

    calc(sx, sy);
    memset(vis, 0, sizeof vis);

    q[0].push({sx, sy});
    vis[sx][sy] = 1;
    int rd = 0;
    for (auto ch : op) {
        rd++;
        int ne = rd % 2;
        int cur = 1 - ne;
        int ban = get_ban(ch);
        while (!q[cur].empty()) {
            auto tp = q[cur].front();
            q[cur].pop();
            int x = tp.first, y = tp.second;
            for (int i = 0; i < 4; i++) {
                if (i == ban) continue;
                int xx = x + dx[i], yy = y + dy[i];
                if (valid(xx, yy)) {
                    q[ne].push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }
    }

    while (!q[rd % 2].empty()) {
        auto u = q[rd % 2].front();
        q[rd % 2].pop();
        int x = u.first, y = u.second;
        if (dist[x][y] == op.size()) {
            grid[x][y] = '!';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
