  int n;
    cin >> n;
    vector<int> du(n + 1), arr(n + 1), next(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
        du[next[i]]++;
    }
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if (du[i] == 0) s.emplace(i);
    }
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        int nex = next[t];
        du[nex]--;
        if (du[nex] == 0) {
            s.emplace(nex);
        }
    }

    auto bfs = [&](int q) {
        int mins = inf;
        stack<int> s;
        s.emplace(q);
        while (!s.empty()) {
            auto i = s.top();
            s.pop();
            mins = min(arr[i], mins);
            du[i] = 0;
            if (du[next[i]] != 0) s.emplace(next[i]);
        }
        return mins;
    };
    int sums = 0;
    for (int i = 1; i <= n; i++) {
        if (du[i]) {
            sums += bfs(i);
        }
    }
    cout << sums << endl;
