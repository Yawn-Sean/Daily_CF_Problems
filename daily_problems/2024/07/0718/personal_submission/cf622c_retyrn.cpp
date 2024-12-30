int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<pii> segs;
    for (int i = 0; i < n; i ++) {
        if (em(segs) or a[segs.back().fi] != a[i]) {
            segs.emplace_back(i, i);
        }
        else segs.back().se = i;
    }
    
    while (q --) {
        int l, r, x;
        cin >> l >> r >> x;
        l --, r --;
        if (a[l] != x) {
            cout << (l + 1) << endl;
            continue;
        }
        if (a[l] != a[r]) {
            if (a[l] == x) {
                cout << (r + 1) << endl;
                continue;
            }
            else {
                cout << (l + 1) << endl;
                continue;
            }
        }
        auto it1 = upper_bound(all(segs), mpr(l, inf));
        it1 --;
        auto it2 = upper_bound(all(segs), mpr(r, inf));
        it2 --;
        if (it1 == it2) {
            cout << -1 << endl;
            continue;
        }
        it1 ++;
        cout << (it1->fi + 1) << endl;
    }
}