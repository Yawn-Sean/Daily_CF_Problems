void solve() {
    cin >> n >> m;
    vector<string> g(n);
    cin >> g;
    
    vector<int> len = {2};
    while (len.back() * 2 <= min(n, m)) {
        len.push_back(len.back() * 2);
    }
    int c = sz(len);

    vector<set<pull>> S(c);
    
    
    for (int st = 0; st < 16; st ++) {
        int t = 1, cur = 2;
        vector<string> gg(2, string(2, '.'));
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 2; j ++) {
                if (st >> (i * 2 + j) & 1) gg[i][j] = '*';
            }
        }
        
        while (cur * 2 <= min(n, m)) {
            vector<string> next(cur << 1, string(cur << 1, '.'));
            for (int i = 0; i < cur; i ++) {
                for (int j = 0; j < cur; j ++) {
                    if (gg[i][j] == '*') next[i*2][j*2] = next[i*2][j*2+1] = next[i*2+1][j*2] = next[i*2+1][j*2+1] = '*';
                    else {
                        if (st & 1) next[i*2][j*2] = '*';
                        if (st >> 1 & 1) next[i*2][j*2+1] = '*';
                        if (st >> 2 & 1) next[i*2+1][j*2] = '*';
                        if (st >> 3 & 1) next[i*2+1][j*2+1] = '*';
                    }
                }
            }
            cur <<= 1;
            Hash2D hs(next);
            S[t ++].insert(hs.get(1, 1, cur, cur));
            gg = move(next);
        }
    }
    
    Hash2D hs(g);
    
    int res = 0;
    for (int k = 0; k < sz(len); k ++) {
        int l = len[k];
        for (int i = 0; i + l - 1 < n; i ++) {
            for (int j = 0; j + l - 1 < m; j ++) {
                auto t = hs.get(i+1, j+1, i + l, j + l);
                res += S[k].count(t);
            }
        }
    }
    
    cout << res << endl;
}