int n;
vector<pii> a(3);

void init() {
    for (auto& [x, y] : a) {
        if (x > y) swap(x, y);
    }
}

bool check1(int x, int y, int z) {
    int sum = a[x].fi + a[y].fi + a[z].fi;
    return a[x].se == a[y].se and a[x].se == a[z].se and a[x].se == sum;
}

bool check2(int x, int y, int z) {
    return a[x].se == a[y].se + a[z].se and a[y].fi == a[z].fi and a[x].fi + a[y].fi == a[x].se;
}

void solve() {
    cin >> a;
    
    for (int st = 0; st < 8; st ++) {
        init();
        for (int i = 0; i < 3; i ++) {
            if (st >> i & 1) {
                swap(a[i].fi, a[i].se);
            }
        }
        
        if (check1(0, 1, 2)) {
            int len = a[0].se;
            cout << len << endl;
            for (int t = 0; t < 3; t ++) {
                for (int i = 0; i < a[t].fi; i ++) {
                    cout << string(len, 'A' + t) << endl;
                }
            }
            return;
        }
        
        vector<int> ids(3);
        iota(all(ids), 0);
        
        do {
            if (check2(ids[0], ids[1], ids[2])) {
                cout << a[ids[0]].se << endl;
                for (int i = 0; i < a[ids[0]].fi; i ++) {
                    cout << string(a[ids[0]].se, 'A' + ids[0]) << endl;
                }
                for (int i = 0; i < a[ids[1]].fi; i ++) {
                    cout << string(a[ids[1]].se, 'A' + ids[1]) + string(a[ids[2]].se, 'A' + ids[2]) << endl;
                }
                return;
            }
        } while (next_permutation(all(ids)));
    }
    cout << -1 << endl;
}