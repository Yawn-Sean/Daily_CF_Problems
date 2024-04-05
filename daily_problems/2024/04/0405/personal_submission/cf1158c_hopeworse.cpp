// link : https://codeforces.com/contest/1158/submission/255051455
// 证明 1 对于以某个端点为对象， 第一个链接到这个端点的是值最大
//       如果对于 u，v都链接 k,如果 u<v, 在value[u]< value[v]的情况下，u会被链接到v 而不会被链接到k
//       因此对于通过端点将大区间分成小区间，最大值一定会在端点
// 证明2  对于每一个区间，其中的点只会链接在区间内
//       （1） 区间的最大值一定会在区间右端点
//        (2)  被分配的区间 左边的区间的右端点 >  右边的区间的右端点
//        我们设 左边区间的一点为 u ,左区间左端点为 v ，右区间链接的点为 k ,右区间右端点为 w
//        如果u链接到k  value[u] < value[k] < value[w] < value[v] 与题目矛盾

void solve() {
    int n;
    cin >> n;
    vector<int> nxt(n + 3), p(n + 3);
    bool flag;
    vector<vector<int>> to(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        if (nxt[i] == -1)nxt[i] = i + 1;
        to[nxt[i]].push_back(i);
    }
    debug(nxt, to);


    function<void(int, int, int)> dfs = [&](int l, int r, int x) {
        debug("dfs", l, r, x);
        if (l > r)return;
        if (nxt[r] != r + 1) {
            flag = 1;
            return;
        }
        if (flag || l == r) {
            if (to[l].size())
                flag = 1;
            p[l] = x;
            return;
        }
        int las = l - 1;
        for (auto i: to[r + 1]) {
            if (i < l || (to[i].size() && to[i].front() < las)) {
                flag = 1;
                return;
            }
            p[i] = x;
            dfs(las + 1, i - 1, x - 1);
            x -= i - las;
            las = i;
        }
    };
    flag = 0;
    dfs(1, n, n);
    if (flag) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    cerr << endl;
}
