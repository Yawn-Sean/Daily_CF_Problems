/*
把每个长方形按照 w, h 升序进行双关键字排序
不妨把 w, h 再做一个离散化
对于排序后的第 i 个长方形，只需要考虑其左边的那些是否可以
利用树状数组，求 < w[i] 的长方形里面最小的 h 是多少
同时使用 map 维护每个 h 对应的最小 w 的长方形编号
*/

struct Rectangle {
    int id, w, h;

    bool operator<(const Rectangle &o) const {
        if (w == o.w) {
            return h < o.h;
        }
        return w < o.w;
    }
};

int n, idx, a[M];
Rectangle r[N];
BIT tr;
map<int, int> hid;

void solve1() {
    cin >> n;
    idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i].w >> r[i].h;
        if (r[i].w > r[i].h) {
            swap(r[i].w, r[i].h);
        }
        r[i].id = i;
        a[++idx] = r[i].w;
        a[++idx] = r[i].h;
    }
    sort(r + 1, r + n + 1);
    sort(a + 1, a + idx + 1);
    int m = unique(a + 1, a + idx + 1) - a - 1;
    for (int i = 1; i <= n; i++) {
        int val = r[i].w;
        r[i].w = lower_bound(a + 1, a + idx + 1, val) - a;
        val = r[i].h;
        r[i].h = lower_bound(a + 1, a + idx + 1, val) - a;
    }
    tr.init(2 * n);
    hid.clear();
    vector<int> res(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int w = r[i].w, h = r[i].h, id = r[i].id;
        int min_h = tr.query(w - 1);
        if (min_h < h) {
            res[id] = hid[min_h];
        }   
        tr.add(w, h);
        if (!hid.count(h)) {
            hid[h] = id;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}  
