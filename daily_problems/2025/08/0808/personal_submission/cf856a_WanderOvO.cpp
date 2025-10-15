/*
考虑 a 中某两数之差为 d，则 b 中不能同时出现 val 和 val + d
预处理出所有的 d，然后 val 从 1 开始枚举，对于能选的 val，留下，并筛掉所有的 val + d
复杂度正确
*/

int n, vis[N], a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        vis[i] = 0;
    }
    sort(a + 1, a + n + 1);
    vector<int> d;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            d.push_back(a[j] - a[i]);
        }
    }

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    vector<int> b;
    for (int i = 1; i < N; i++) {
        if (b.size() == n) {
            break;
        }

        if (!vis[i]) {
            b.push_back(i);
            for (auto dd : d) {
                if (dd + i < N) {
                    vis[dd + i] = 1;
                }
            }
        }
    }

    if (b.size() == n) {
        cout << "YES\n";
        for (auto val : b) {
            cout << val << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}
