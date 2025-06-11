/*
n = 5000
考虑直接模拟，每轮按照深度从小到大去模拟走动情况
至多模拟多少轮呢？每轮至少有一个点走到 1
*/

struct Edge {
    int v, w;
};

int n, a[N], fa[N], w[N], d[N], res[N];
vector<vector<Edge>> e(N);
vector<priority_queue<PII, vector<PII>, greater<PII>>> cur_ids(N);

void pre(int u, int f, int depth, int limit) {
    d[u] = depth;
    fa[u] = f;
    w[u] = limit;
    for (auto edge : e[u]) {
        int v = edge.v;
        if (v != f) {
            pre(v, u, depth + 1, edge.w);
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    pre(1, 0, 0, 0);

    vector<int> order;
    for (int i = 1; i <= n; i++) {
        order.push_back(i);
    }
    sort(order.begin(), order.end(), [&] (int i, int j) -> bool {
        return d[i] < d[j];
    });

    for (int i = 1; i <= n; i++) {
        cur_ids[i].push({a[i], i});
    }

    for (int rd = 0; rd <= 2 * n; rd++) {
        bool all_finished = true;
        for (auto v : order) {
            if (v == 1) {
                while (!cur_ids[v].empty()) {
                    auto ver = cur_ids[v].top();
                    cur_ids[v].pop();
                    res[ver.y] = rd;
                    all_finished = false;
                }
            } else {
                int cnt = 0;
                while (!cur_ids[v].empty()) {
                    auto ver = cur_ids[v].top();
                    cur_ids[v].pop();
                    all_finished = false;
                    cnt++;
                    if (cnt <= w[v]) {
                        cur_ids[fa[v]].push(ver);
                    } else {
                        cur_ids[v].push(ver);
                        break;
                    }
                }
            }
        }
        if (all_finished) {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}  
