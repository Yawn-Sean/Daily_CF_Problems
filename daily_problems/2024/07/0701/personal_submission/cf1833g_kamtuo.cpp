
void add(int u, int v, int i) {
    ne[idx] = h[u];
    d[idx] = v;
    e[idx] = i;
    h[u] = idx ++;
}

void dfs(int now, int fa) {
    sz[now] = 1;
    for (int i = h[now]; i; i = ne[i]) {
        int j = d[i];
        if (j == fa) continue;
        dfs(j, now);
        if (sz[j] == 3) {
            ans.push_back(e[i]);
        } else {
            sz[now] += sz[j];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        ans.clear();
        idx = 1;
        ok = true;
        for (int i = 1; i <=n; i ++) {
            h[i] = 0;
            sz[i] = 0;
        }
        for (int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            add(u, v, i);
            add(v, u, i);
        }
        dfs(1, -1);
        if (sz[1] != 3) ok = false;
        if (ok) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i ++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    } 
    return 0;
}
