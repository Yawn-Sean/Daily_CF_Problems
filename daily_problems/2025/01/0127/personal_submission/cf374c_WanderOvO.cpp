/*
没有 DIMA 的情况很好判断
枚举不同起点 D 做 BFS 时，不清除之前的标记是否有影响？
DIMA
  I
  D
  A
DIM
如果从左上角的 D 做 BFS 且不清除标记，则左下角的 D 就没法走出来两个
把问题转化一下，把网格改成有向图，则问题变成了判断是否有环，没环的话说明是 DAG，约等于求最长链
拓扑排序 + DP 即可
dp[i][j]: 终点是 i 结点，且以 j 字符开头的最长链有多长
*/ 

string grid[M];
int n, m, d[N], dp[N][4];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
unordered_map<char, char> ne;
unordered_map<char, int> char_to_int;
vector<vector<int>> e(N);

int get_id(int x, int y) {
    return y + (x - 1) * m;
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    ne['D'] = 'I';
    ne['I'] = 'M';
    ne['M'] = 'A';
    ne['A'] = 'D';
    char_to_int['D'] = 0;
    char_to_int['I'] = 1;
    char_to_int['M'] = 2;
    char_to_int['A'] = 3;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cur = grid[i][j];
            for (int k = 0; k < 4; k++) {
                int xx = dx[k] + i, yy = dy[k] + j;
                if (xx > 0 && xx <= n && yy > 0 && yy <= m && grid[xx][yy] == ne[cur]) {
                    e[get_id(i, j)].push_back(get_id(xx, yy));
                    d[get_id(xx, yy)]++;
                }
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = get_id(i, j);
            for (int k = 0; k < 4; k++) {
                dp[id][k] = -INF;
            }
            if (d[id] == 0) {
                q.push(id);
                dp[id][char_to_int[grid[i][j]]] = 1;
            }
        }
    }
    vector<int> seq;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        seq.push_back(u);
        for (auto v : e[u]) {
            d[v]--;
            for (int i = 0; i < 4; i++) {
                dp[v][i] = max(dp[u][i] + 1, dp[v][i]);
            }
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
    if (seq.size() != n * m) {
        cout << "Poor Inna!\n";
        return;
    }

    int res = 0;
    for (int i = 1; i <= n * m; i++) {
        res = max(res, dp[i][0] / 4);
        res = max(res, (dp[i][1] - 3) / 4);
        res = max(res, (dp[i][2] - 2) / 4);
        res = max(res, (dp[i][3] - 1) / 4);
    }
    if (res == 0) {
        cout << "Poor Dima!\n";
        return;
    }
    cout << res << "\n";
}
