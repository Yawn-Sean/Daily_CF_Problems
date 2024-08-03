void solve() {
    int n;
    cin >> n;
    vector<node> trie(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "IN") {
            trie[i].type = IN;
            cin >> trie[i].val;
        } else if (s == "AND") {
            trie[i].type = AND;
            cin >> trie[i][0] >> trie[i][1];
        } else if (s == "XOR") {
            trie[i].type = XOR;
            cin >> trie[i][0] >> trie[i][1];
        } else if (s == "OR") {
            trie[i].type = OR;
            cin >> trie[i][0] >> trie[i][1];
        } else if (s == "NOT") {
            trie[i].type = NOT;
            cin >> trie[i][0];
        }
    }
//    vector<int> tag(n + 1);
    auto dfs = [&](auto self, int x) {
        if (trie[x].type == IN) {
            return;
        } else if (trie[x].type == AND) {
            self(self, trie[x][0]);
            self(self, trie[x][1]);
            trie[x].val = trie[trie[x][0]].val & trie[trie[x][1]].val;
            if (trie[trie[x][0]].val == 0) trie[trie[x][1]].tag = 1;
            if (trie[trie[x][1]].val == 0) trie[trie[x][0]].tag = 1;
        } else if (trie[x].type == XOR) {
            self(self, trie[x][0]);
            self(self, trie[x][1]);
            trie[x].val = trie[trie[x][0]].val ^ trie[trie[x][1]].val;
        } else if (trie[x].type == OR) {
            self(self, trie[x][0]);
            self(self, trie[x][1]);
            trie[x].val = trie[trie[x][0]].val | trie[trie[x][1]].val;
            if (trie[trie[x][0]].val == 1) trie[trie[x][1]].tag = 1;
            if (trie[trie[x][1]].val == 1) trie[trie[x][0]].tag = 1;
        } else if (trie[x].type == NOT) {
            self(self, trie[x][0]);
            trie[x].val = !trie[trie[x][0]].val;
        }
    };
    auto dfs2 = [&](auto self, int x) {
        if (x == 0)return;
        if (trie[x].tag) {
            if (trie[x][0] != 0) {
                trie[trie[x][0]].tag = 1;
            }
            if (trie[x][1] != 0) {
                trie[trie[x][1]].tag = 1;
            }

        }
        if (trie[x][0] != 0) {
            self(self, trie[x][0]);
        }
        if (trie[x][1] != 0) {
            self(self, trie[x][1]);
        }
        return;

    };

    dfs(dfs, 1);
    dfs2(dfs2, 1);
    for (int i = 1; i <= n; i++) {
        debug(i, trie[i].val, trie[i].type, trie[i].tag);
    }
    for (int i = 1; i <= n; i++) {
        if (trie[i].type == IN) {
            cout << (1 ^ trie[i].tag ^ trie[1].val);
        }
    }

}
