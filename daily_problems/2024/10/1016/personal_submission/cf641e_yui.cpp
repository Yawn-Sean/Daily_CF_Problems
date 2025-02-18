#define int i64

void solve() {
    int n;
    cin >> n;
    vec<int> ans;
    map<int, vec<array<int, 3>>> rec;
    int qid = 0;
    for (int i = 0; i < n; i++) {
        int a, t, x;
        cin >> a >> t >> x;
        rec[x].push_back({t, a, a == 3 ? qid++ : -1});
    }
    ans.resize(qid);

    for (auto & [k, v] : rec) {
        int m = v.size();
        vec<int> des(m);
        for (int i = 0; i < m; i++) {
            des[i] = v[i][0];
        }
        fenwick<int> tr(m + 10);
        ranges::sort(des);
        for (int i = 0; i < m; i++) {
            auto [time, a, id] = v[i];
            int cur = ranges::lower_bound(des, time) - des.begin();

            if (a == 1) {
                tr.add(cur, 1);
            } else if (a == 2) {
                tr.add(cur, -1);
            } else {
                ans[id] = tr.sum(cur + 1);
            }
        }
    }

    for (auto & i : ans) {
        cout << i << '\n';
    }
}
