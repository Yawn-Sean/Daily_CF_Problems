int n, m, h;

void solve() {
    cin >> h >> m >> n;
    int idx = 0;
    vector<set<pii>> S;
    vector<int> id(h, -1);
    vector<int> pos(h, -1);
    vector<int> size;

    for (int i = 0; i < h; i ++) {
        if (id[i] >= 0) continue;
        int x = i;
        S.push_back(set<pii>());
        int p = 0;
        while (id[x] == -1) {
            id[x] = idx;
            pos[x] = p;
            S[idx].insert(mpr(p, x));
            x += m;
            if (x >= h) x -= h;
            p ++;
        }
        idx ++;
        size.push_back(p);
    }
    map<int, int> mp;
    ll res = 0;
    
    while (n --) {
        string op;
        int val, x;
        cin >> op >> val;
        
        if (op[0] == '+') {
            cin >> x;
            int idx = id[x], p = pos[x];
            auto& st = S[idx];
            auto it = st.lower_bound(mpr(p, x));
            if (it != st.end()) {
                auto y = it->se;
                mp[val] = y;
                res += pos[y] - pos[x];
                st.erase(it);
            }
            else {
                it = st.begin();
                auto y = it->se;
                mp[val] = y;
                res += pos[y] + size[idx] - pos[x];
                st.erase(it);
            }
        }
        else {
            x = mp[val];
            int idx = id[x], p = pos[x];
            S[idx].insert(mpr(p, x));
        }
    }
    
    cout << res << endl;
    
}