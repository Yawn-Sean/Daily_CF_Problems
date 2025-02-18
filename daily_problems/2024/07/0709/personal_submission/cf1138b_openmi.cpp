void solve() {
    int n;
    cin >> n;
    string sc, sa;
    cin >> sc >> sa;
    vi vc, va, vo, vb;
    rep (i, 0, n) {
        if (sc[i] == '1' and sa[i] == '1') vb.push_back(i + 1);
        else if (sc[i] == '1') vc.push_back(i + 1);
        else if (sa[i] == '1') va.push_back(i + 1);
        else vo.push_back(i + 1);
    }
    int b = vb.size(), c = vc.size(), a = va.size(), o = n - c - b - a;

    vi ans;
    if (c >= a + b) {
        if (c > n / 2) return cout << -1 << nl, void();
        else {
            rep (i, 0, a + b) {
                ans.push_back(vc[i]);
            }
            int r = n / 2 - ans.size();
            rep(i, 0, r) ans.push_back(vo[i]);
        }
    } else if (a >= c + b) {
        if (a > n / 2)  return cout << -1 << nl, void();
        else {
            rep(i, 0, c) ans.push_back(vc[i]);
            rep(i, 0, b) ans.push_back(vb[i]);
            rep(i, 0, a - c - b) ans.push_back(va[i]);
            int r = n / 2 - ans.size();
            rep(i, 0, r) ans.push_back(vo[i]);
        }
    } else {
        if (c + a == 0 and (b & 1)) return cout << -1 << nl, void();
        else if (c >= a) {
            int t = c - a;
            if ((b - t) % 2) {
                rep (i, 0, c - 1) ans.push_back(vc[i]);
                rep (i, 0, (b - t) / 2 + 1) ans.push_back(vb[i]);
                int r = n / 2 - ans.size();
                rep (i, 0, r) ans.push_back(vo[i]);
            } else {
                rep (i, 0, c) ans.push_back(vc[i]);
                rep (i, 0, (b - t) / 2) ans.push_back(vb[i]);
                int r = n / 2 - ans.size();
                rep (i, 0, r) ans.push_back(vo[i]);;
            }
        } else {
            int t = a - c;
            if ((b - t) % 2) {
                rep (i, 0, c) ans.push_back(vc[i]);
                rep (i, 0, t + (b - t) / 2) ans.push_back(vb[i]);
                ans.push_back(va[0]);
                int r = n / 2 - ans.size();
                rep (i, 0, r) ans.push_back(vo[i]);
            } else {
                rep (i, 0, c) ans.push_back(vc[i]);
                rep (i, 0, t + (b - t) / 2) ans.push_back(vb[i]);
                int r = n / 2 - ans.size();
                rep(i, 0, r) ans.push_back(vo[i]);
            }
        }
    }

    printv(ans, ' ', false);
    cout << nl;
}
