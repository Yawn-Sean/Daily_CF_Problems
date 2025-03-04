/*
将 b 插入到 trie 中，对于 a[i]，贪心匹配使得异或最小
*/

int trie[M][2], cnt[M], idx = 0, a[N], n;

void insert(int val) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (!trie[p][ch]) {
            trie[p][ch] = ++idx;
        }
        p = trie[p][ch];
        cnt[p]++;
    }
}

int query(int val) {
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (cnt[trie[p][ch]]) {
            res = 2 * res;
            cnt[trie[p][ch]]--;
            p = trie[p][ch];
        } else if (cnt[trie[p][ch ^ 1]]) {
            res = 2 * res + 1;
            cnt[trie[p][ch ^ 1]]--;
            p = trie[p][ch ^ 1];
        } 
    }
    return res;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        insert(val);
    }

    for (int i = 1; i <= n; i++) {
        cout << query(a[i]) << " ";
    }
    cout << "\n";
}   
