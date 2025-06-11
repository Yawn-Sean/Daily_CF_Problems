void solve() {
    int n, m;
    cin >> n;
    int len = n + 1;
    vector<int> p(len), next(len);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> m;
    vector<int> vis(len);
    vector<vector<int>> cycles; 
    auto rebuild = [&]() -> void {
        for (int i = 1; i <= n; i++) next[p[i]] = i;
        fill(all(vis), 0);
        cycles.clear();
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int cur = i;
            vector<int> cyc;
            while (!vis[cur]) {
                vis[cur] = true;
                cyc.emplace_back(cur);
                cur = next[cur];
            }
            sort(all(cyc));
            cycles.emplace_back(cyc);
        }
    };
    rebuild();
    int k = cycles.size();
    if (n - k > m) {
        cout << n - k - m << endl;
        while (n - k > m) {
            int minIndex = len, cycleID = -1;
            for (int i = 0; i < cycles.size(); i++) {
                auto& cyc = cycles[i];
                if (cyc.size() > 1 && *cyc.begin() < minIndex) {
                    minIndex = *cyc.begin();
                    cycleID = i;
                }
            }
            int target = len;
            for (int x : cycles[cycleID]) {
                if (x != minIndex) target = min(x, target);
            }
            cout << minIndex << " " << target << " ";
            swap(p[minIndex], p[target]);
            rebuild();
            k++;
        }
    } else if (n - k < m) {
        cout << m - n + k << endl;
        while (n - k < m) {
            int minIndex = len;
            for (int i = 0; i < cycles.size(); i++) {
                auto& cyc = cycles[i];
                if (*cyc.begin() != 1 && *cyc.begin() < minIndex) {
                    minIndex = *cyc.begin();
                }
            }
            swap(p[1], p[minIndex]);
            cout << 1 << " " << minIndex << " ";
            rebuild();
            k--;
        }
    } else {
        cout << 0;
    }
    cout << endl;
}
