struct Compare {
    bool operator()(array<int, 2> u, array<int, 2> v) {
        return abs(u[0]) > abs(v[0]);
    }
};
void Solve() {
    int n, k, x;cin >> n >> k >> x;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1;i <= n;i++) {
        int x;cin >> x;
        a[i] = { x,i };
    }
    vector<int> res(n + 1);
    sort(a.begin() + 1, a.end());
    int fu = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i][0] < 0) {
            fu++;
        }
    }
    auto run = [&](const vector<array<int, 2>>& a) {
        vector<int> res(n + 1);
        priority_queue <array<int, 2>, vector<array<int, 2>>, Compare> q;
        for (int i = 1;i <= n;i++) {
            q.push(a[i]);
        }
        for (int i = 1;i <= k;i++) {
            auto [u, id] = q.top();q.pop();
            if (u >= 0) u += x;
            else u -= x;
            q.push({ u,id });
        }
        for (int i = 1;i <= n;i++) {
            auto [u, id] = q.top();q.pop();
            res[id] = u;
        }
        return res;
        };
    if (fu % 2 == 0) {
        auto ptr = lower_bound(a.begin() + 1, a.end(), array<int, 2>{ 0, 0 }) - a.begin();
        if (ptr == 1) {
            int xuyao = a[ptr][0] / x + 1;
            if (xuyao > k) {
                a[ptr][0] -= k * x;
                k = 0;
            }
            else {
                k -= xuyao;
                a[ptr][0] -= xuyao * x;
            }
        }
        else if (ptr == n + 1) {
            ptr--;
            int xuyao = abs(a[ptr][0]) / x + 1;
            if (xuyao > k) {
                a[ptr][0] += k * x;
                k = 0;
            }
            else {
                k -= xuyao;
                a[ptr][0] += xuyao * x;
            }
        }
        else {
            if (a[ptr][0] > abs(a[ptr - 1][0])) {
                ptr--;
                int xuyao = abs(a[ptr][0]) / x + 1;
                if (xuyao > k) {
                    a[ptr][0] += k * x;
                    k = 0;
                }
                else {
                    k -= xuyao;
                    a[ptr][0] += xuyao * x;
                }
            }
            else {
                int xuyao = a[ptr][0] / x + 1;
                if (xuyao > k) {
                    a[ptr][0] -= k * x;
                    k = 0;
                }
                else {
                    k -= xuyao;
                    a[ptr][0] -= xuyao * x;
                }
            }
        }
    }

    res = run(a);

    for (int i = 1;i <= n;i++) cout << res[i] << " \n"[i == n];
}
