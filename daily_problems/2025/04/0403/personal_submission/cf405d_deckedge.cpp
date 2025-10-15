void solve() {
    const int s = 1e6;
    int n = read();
    vector<bool> vis(s + 1, false);
    vector<int> a(n), res;
    generate(all(a), read);
    for (int x : a) {
        vis[x] = true;
    }
    int cnt = 0;
    for (int x : a) {
        if (!vis[s - x + 1]) {
            res.emplace_back(s - x + 1);
            vis[s - x + 1] = true;
        } else {
            cnt++;
        }
    }
    for (int i = 1; i < s + 1 && cnt; i++) {
        if (!vis[i] && !vis[s - i + 1]) {
            res.emplace_back(i);
            res.emplace_back(s - i + 1);
            vis[i] = true;
            vis[s - i + 1];
            cnt -= 2;
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " \n"[i == res.size() - 1];
    }
}
