/*
0 是起点，只能有 1 个
1 是和起点邻接的
2 是和 1 邻接的
距离不能跳跃
依次这样做下去，只要还有剩余的度数就可以构造
*/

int d[N], n, k;
vector<vector<PII>> vs(N);

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            if (root == -1) {
                root = i;
            } else {
                cout << "-1\n";
                return;
            }
        }
    }

    if (root == -1) {
        cout << "-1\n";
        return;
    }

    vs[0].push_back({root, k});
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i = 1; i <= n; i++) {
        if (d[i] != 0) {
            pq.push({d[i], i});
        }
    }

    vector<PII> es;
    while (!pq.empty()) {
        PII tp = pq.top();
        pq.pop();
        int u = tp.y, dist = tp.x;
        if (vs[dist - 1].size() == 0) {
            cout << "-1\n";
            return;
        }

        PII &last = vs[dist - 1].back();
        last.y--;
        if (k - 1 > 0)
            vs[dist].push_back({u, k - 1});
        es.push_back({u, last.x});
        if (last.y == 0) {
            vs[dist - 1].pop_back();
        }
    }

    cout << es.size() << "\n";
    for (auto e : es) {
        cout << e.x << " " << e.y << "\n";
    }
}
