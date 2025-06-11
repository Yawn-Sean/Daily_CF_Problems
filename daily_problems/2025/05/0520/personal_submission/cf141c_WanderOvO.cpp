/*
按照前面比自己大的数有多少个，从小到大去确定相对的大小
先把 0 的都搞上，然后看更大的，遇到之后就暴力遍历，插入
*/

map<int, string> id;
int n, cnt[N], rk[N], val[N], res[N], ids[N];
PII ps[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name >> cnt[i];
        id[i] = name;
        ps[i] = {cnt[i], i};
    }
    sort(ps + 1, ps + n + 1);
    
    for (int i = 1; i <= n; i++) {
        int bigger_cnt = ps[i].x, id = ps[i].y;
        int pos = bigger_cnt + 1;
        if (pos > i) {
            cout << "-1\n";
            return;
        }
        for (int j = i - 1; j >= pos; j--) {
            res[j + 1] = res[j];
            ids[j + 1] = ids[j];
        }
        if (i == 1) {
            res[pos] = 1e9;
            val[id] = 1e9;
        } else {
            int mn = 1e9;
            for (int j = 1; j < pos; j++) {
                mn = min(mn, res[j]);
            }
            res[pos] = mn - 1;
            val[id] = mn - 1; 
        }
        ids[pos] = id;
    }

    for (int i = 1; i <= n; i++) {
        int j = ids[i];
        cout << id[j] << " " << val[j] << "\n";
    }
}   
