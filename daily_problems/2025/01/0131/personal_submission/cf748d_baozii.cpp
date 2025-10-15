int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    umap<string, vi> w;
    umap<int, vi> v;
    umap<string, int> pos;
    vector<string> a;
    uset<string> st;
    rep(i, 0, k) {
        string s;
        int c;
        cin >> s >> c;
        w[s].pb(c);
        st.insert(s);
    }
    int p = 0;
    for (auto s : st) {
        sort(ALL(w[s]));
        pos[s] = p++;
        a.pb(s);
    }
    rep(i, 0, a.size()) v[i] = w[a[i]];
    int tot = 0, mx = 0;
    for (auto str : st) {
        string revs = str;
        reverse(ALL(revs));
        if (str == revs) continue;
        int s = pos[str];
        if (!pos.contains(revs)) continue;
        int rev = pos[revs];
        while (!v[s].empty() && !v[rev].empty()) {
            if (v[s].back() + v[rev].back() > 0) {
                tot += v[s].back() + v[rev].back();
                v[s].pop_back();
                v[rev].pop_back();
            } else {
                break;
            }
        }
    }
    vi mmx, rv;
    for (auto str : st) {
        string revs = str;
        reverse(ALL(revs));
        if (str != revs) continue;
        int s = pos[str];
        int rev = pos[revs];
        while (v[s].size() > 1) {
            int v1 = v[s].back();
            v[s].pop_back();
            int v2 = v[s].back();
            v[s].pop_back();
            if (v1 > 0 && v2 > 0) {
                tot += v1 + v2;
            } else if (v1 > 0 && v2 <= 0) {
                if (v1 + v2 > 0) {
                    mmx.pb(v1 + v2);
                    rv.pb(v1);
                    tot += v1 + v2;
                } else {
                    mx = max(mx, v1);
                }
            } else {
                break;
            }
        }
        if (!v[s].empty()) mx = max(mx, v[s][0]);
    }
    int ans = tot + mx;
    rep(i, 0, rv.size()) {
        ans = max(ans, tot - mmx[i] + max(mx, rv[i]));
    }
    cout << ans << "\n";
}
