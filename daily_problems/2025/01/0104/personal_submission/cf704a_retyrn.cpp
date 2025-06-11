int n, m;

void solve() {
    cin >> n >> m;
    
    int res = 0;
    vector<int> cnt(n + 1), time(n + 1, 0), q;
    int cur = 0;
    
    while (m --) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cnt[x] += 1;
            res += 1;
            q.pbk(x);
        }
        else if (op == 2) {
            res -= cnt[x];
            cnt[x] = 0;
            time[x] = sz(q);
        }
        else {
            while (cur < x) {
                if (cur >= time[q[cur]]) {
                    res --;
                    cnt[q[cur]] --;
                }
                cur ++;
            }
        }
        cout << res << endl;
    }
}