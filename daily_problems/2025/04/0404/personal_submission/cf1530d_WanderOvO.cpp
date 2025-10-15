/*
将一个数组通过最少的改动变成错位排列
连有向边 (i, a[i])
如果是一个错位排列的话，则建出来的图应该是一系列 >= 2 元的环
自环一定要改造
每个点的出度都恰好是 1，入度也必须是 1
我们先把所有的 >= 2 元的环剪出来，环上的点都不用改
对于环外的点以及自环，这些要想办法串成一个环
我们把链按照顺序剪出来，首尾相连，即可做到这一点
如果只有一个点要改，就得破开某个已有的环
*/

int n, a[N], d[N], b[N];
vector<vector<int>> e(N);
vector<vector<int>> re(N);

void dfs(int u, vector<int> &chain) {
    chain.push_back(u);
    for (auto v : re[u]) {
        dfs(v, chain);
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        re[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        e[i].push_back(a[i]);
        d[a[i]]++;
        re[a[i]].push_back(i);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<vector<int>> chains;
    for (int i = 1; i <= n; i++) {
        if (d[i] != 0) {
            for (auto v : re[i]) {
                if (d[v] == 0) {
                    vector<int> chain;
                    dfs(v, chain);
                    reverse(chain.begin(), chain.end());
                    chains.push_back(chain);
                }
            }
        } 
    }

    vector<int> need_to_change;
    for (int i = 0; i < chains.size(); i++) {
        for (auto v : chains[i]) {
            need_to_change.push_back(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            need_to_change.push_back(i);
        }
    }

    if (need_to_change.size() > 1) {
        for (int i = 0; i < need_to_change.size(); i++) {
            int j = (i + 1) % need_to_change.size();
            int u = need_to_change[i], v = need_to_change[j];
            b[u] = v;
        }
    } else if (need_to_change.size() == 1) {
        if (b[need_to_change[0]] == need_to_change[0]) {
            // 如果这个唯一要改的点原本是自环
            for (int i = 1; i <= n; i++) {
                if (i != need_to_change[0]) {
                    int tmp = b[i];
                    b[i] = need_to_change[0];
                    b[need_to_change[0]] = tmp;
                    break;
                }
            }
        } else {
            // 如果这个唯一要改的点原本是单点链
            int tmp = b[need_to_change[0]];
            int last = -1;
            for (int i = 1; i <= n; i++) {
                if (b[i] == tmp && i != need_to_change[0]) {
                    last = i;
                    break;
                }
            }
            assert(last != -1);
            b[last] = need_to_change[0];
        }
    } 

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            res++;
        }
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << "\n";
}
