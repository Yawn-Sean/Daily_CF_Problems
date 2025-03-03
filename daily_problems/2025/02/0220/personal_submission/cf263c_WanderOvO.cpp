/*
先把图建出来
1 假如连接了 2 3 4 5
我如果能确定前 3 个数是谁，比如 1 2 3，那么第 4 个数必须和 2 和 3 都相连，且不是 1
所以枚举 2 3 4 5 中拿出一个大小为 2 的排列，和 1 组成前 3 个点，然后按照顺序检查即可
A(4, 2) = 12，所以复杂度 O(12 * n)

*/

vector<set<int>> e(N);
int n;
bool vis[N];
vector<int> path;

int lowbit(int x) {
    return x & -x;
}

int get_cnt(int x) {
    int res = 0;
    while (x > 0) {
        res++;
        x -= lowbit(x);
    }
    return res;
}

bool check() {
    memset(vis, 0, sizeof vis);
    vis[path[0]] = true;
    vis[path[1]] = true;
    vis[path[2]] = true;
    for (int i = 2; i < n - 1; i++) {
        vis[path[i]] = true;
        int u1 = path[i], u2 = path[i - 1], u3 = path[i - 2];
        for (auto v : e[u1]) {
            if (e[u2].count(v) && !vis[v]) {
                path.push_back(v);
                break;
            }
        }
        if (path.size() != i + 2) {
            return false;
        }
    }
    if (!e[path.back()].count(1) || !e[1].count(path.back()) || !e[path[1]].count(path.back()) || !e[path.back()].count(path[1])) {
        return false;
    }
    for (int i = 0; i + 2 < n; i++) {
        if (!e[path[i]].count(path[i + 2]) || !e[path[i + 2]].count(path[i])) {
            return false;
        }
    }
    return true;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
        if (e[i].size() != 4) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> adjs;
    for (auto v : e[1]) {
        adjs.push_back(v);
    }
    for (int i = 0; i < 16; i++) {
        if (get_cnt(i) == 2) {
            vector<int> head;
            for (int j = 0; j < 4; j++) {
                if ((i >> j) & 1) {
                    head.push_back(adjs[j]);
                }
            }
            if (!e[head[0]].count(head[1])) {
                continue;
            }

            path.clear();
            path.push_back(1);
            path.push_back(head[0]);
            path.push_back(head[1]);
            if (check()) {
                for (auto v : path) {
                    cout << v << " ";
                }
                return;
            }

            path.clear();
            path.push_back(1);
            path.push_back(head[1]);
            path.push_back(head[0]);
            if (check()) {
                for (auto v : path) {
                    cout << v << " ";
                }
                return;
            }
        }
    }
    cout << "-1\n";
}
