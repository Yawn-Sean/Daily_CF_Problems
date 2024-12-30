void solve() {
    int n;
    cin >> n;
    vi x(n), y(n), r(n);
    rep (i, 0, n) {
        cin >> x[i] >> y[i] >> r[i];
    }
    ll x1, y1, r1, x2, y2, r2, s1, s2;
    auto f = [&](ll a, ll b) {return a*a + b*b;};

    vc<vi> g(n);
    rep (i, 0, n) {
        x1 = x[i], y1 = y[i], r1 = r[i];
        rep (j, i + 1, n) {
            x2 = x[j], y2 = y[j], r2 = r[j];
            s1 = f(x1 - x2, y1 - y2);
            s2 = (r1 + r2) * (r1 + r2);
            if (s1 == s2) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vi col(n, -1);
    vi st;
    int ok = 0;
    rep (i, 0, n) {
        if (col[i] == -1) {
            int u, c0 = 1, c1 = 0, f = 1;
            col[i] = 0;
            st.push_back(i);
            while (!st.empty()) {
                u = st.back();
                st.pop_back();
                for (int v: g[u]) {
                    if (col[v] == -1) {
                        col[v] = col[u] ^ 1;
                        if (col[v]) c1 ++;
                        else c0++;
                        st.push_back(v);
                    } else if (col[u] ^ col[v] != 1) {
                        f = 0;
                    }
                }
            }
            if (c0 != c1 and f) {
                ok = 1;
                break;
            }
        }
    }
    if (ok == 1) p(1);
    else p(0);
}
