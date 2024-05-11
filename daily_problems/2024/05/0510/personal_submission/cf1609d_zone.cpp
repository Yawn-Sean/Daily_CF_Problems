void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> p(n + 1),  cnt(n + 1, 1);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int v = 0;
    
    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };
    
    for (int i = 0; i < d; i ++ ) {
        int a, b;
        cin >> a >> b;
        auto pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pb] = pa;
            cnt[pa] += cnt[pb];
        } else {
            v ++;
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; i ++ ) {
            if (p[i] == i) q.push(cnt[i]);
        }
        int ans = 0;
        for (int i = 0; i <= v && !q.empty(); i ++ ) {
            ans += q.top();
            q.pop();
        }
        cout << ans - 1 << "\n";
    }

}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
