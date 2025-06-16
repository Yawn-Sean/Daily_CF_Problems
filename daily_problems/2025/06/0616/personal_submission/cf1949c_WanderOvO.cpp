/*
u 的所有蚂蚁都移动到 v 了，则没有蚂蚁能够移动到 u 了
观察到一个事情，假如一个点符合题意，则其必须连着至少一个度为 1 的点
否则，要么邻接点蚂蚁数严格大于自己，转移不过来，或者邻接点转移过来之后邻接点的其他邻接点转移过不来了
枚举每个度为 1 的点，尝试将其值转移到唯一的邻接点上，更新度
然后继续做这个事情
每次只能尝试从当前度为 1 的点去转移到别的点，否则一定会漏点
按照什么顺序枚举度为 1 的点呢？有没有可能先遍历到一个比较大的点，然后转移不过去？人为规定必须从蚂蚁数小的开始转移
*/

vector<vector<int>> e(N);
int n, d[N], cnt[N];
bool deleted[N];

void meibao() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (n == 1) {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] = 1;
    }

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            pq.push({cnt[i], i});
        }
    }
    while (!pq.empty()) {
        auto tp = pq.top();
        int u = tp.y;
        pq.pop();
        for (auto v : e[u]) {
            if (!deleted[v]) {
                if (cnt[v] >= cnt[u]) {
                    deleted[u] = true;
                    cnt[v] += cnt[u];
                    d[v]--;
                    if (d[v] == 1) {
                        pq.push({cnt[v], v});
                    }
                } else {
                    break;
                }
            }
        }
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!deleted[i]) {
            c++;
        }
    }
    if (c != 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
