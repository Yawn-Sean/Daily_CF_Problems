/*
这个问题的要求非常高，需要同一个队伍里的人两两认识
认识是没有传递性的
这需要 (n / 2) * (n / 2 - 1) 个关系
所以当 n > 2000 时，是一定满足不了的
n <= 2000 时，先判断 m 是否比这个小，比这个小的也不用考虑了
更大的 m 考虑如何做
能不能反向考虑，看怎样的两个点一定不可能在同一个集合中
显然，不直接相连的两个点一定在不同集合中
假如我们根据互斥关系建图的话，如果有奇数环则无解，所以变成了二分图判定问题
注意，n 为奇数时显然是不行的，我们要判定的是偶数点数的二分图
并且还有个问题，即使是二分图，拼凑起来的时候，需要注意个数相等
并非无脑把染色一样的点都放一起
我们需要记录每个二分图连通分量里两种颜色的个数，最后用一个 DP 去检查，记录方案
本地可以评测，可以写一下
*/

int n, m;
int w[M][M], color[M];
bool dp[M][M];
int from[M][M];
char res[M];
bool vis[M];
vector<int> nodes;
vector<vector<int>> r, b;

bool dfs(int u, int c) {
    color[u] = c;
    nodes.push_back(u);
    bool ok = true;
    for (int v = 1; v <= n; v++) {
        if (w[u][v] == 0) {
            if (color[v] == -1) {
                ok &= dfs(v, c ^ 1);
            } else {
                if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return ok;
}

void solve() {
    cin >> n >> m;
    if (n > 2000 || n % 2 != 0) {
        cout << "impossible\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        w[i][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        w[u][v] = w[v][u] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            nodes.clear();
            if (!dfs(i, 0)) {
                cout << "impossible\n";
                return;
            }
            
            vector<int> rr, bb;
            for (auto v : nodes) {
                if (color[v] == 0) {
                    rr.push_back(v);
                } else {
                    bb.push_back(v);
                }
            }
            
            if (r.size() == 0) {
                vector<int> empty_list;
                r.push_back(empty_list);
                b.push_back(empty_list);
            }
            
            r.push_back(rr);
            b.push_back(bb);
        }
    }
    
    dp[0][0] = true;
    int len = r.size();
    len--;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= r[i].size()) {
                if (dp[i - 1][j - r[i].size()]) {
                    dp[i][j] |= dp[i - 1][j - r[i].size()];   
                    from[i][j] = 0;
                }
            }
            if (j >= b[i].size()) {
                if (dp[i - 1][j - b[i].size()]) {
                    dp[i][j] |= dp[i - 1][j - b[i].size()];
                    from[i][j] = 1;   
                }
            }
        }
    }
    
    if (!dp[len][n / 2]) {
        cout << "impossible\n";
        return;
    }
    
    int left_cnt = n / 2;
    for (int i = len; i > 0; i--) {
        if (from[i][left_cnt] == 0) {
            for (auto v : r[i]) {
                res[v] = 'r';
            }
            left_cnt -= r[i].size();
        } else {
            for (auto v : b[i]) {
                res[v] = 'r';
            }
            left_cnt -= b[i].size();
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (res[i] != 'r') {
            res[i] = 'b';
        }
    }
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (res[i] == res[j]) {
    //             if (!w[i][j]) {
    //                 cout << "fuck\n";
    //                 exit(1);
    //             }
    //         }
    //     }
    // }
    // int c = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (res[i] == 'r') {
    //         c++;
    //     }
    // }
    // if (c != n - c) {
    //     exit(1);
    // } 
    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
}
