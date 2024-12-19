/*
考虑对手上一次选了什么
- 假如选了死敌中的一个，则自己必须跟上
- 假如选的不属于任何一个死敌对，也不一定选当前最大的
100 90 89 1，90 和 1 是死敌
假如先选 100，则对方选 90，自己只能选 1，对方再选 89，输了
假如先选 90，则对方选 1，自己再选 100，对方 89，大赢

假如自己先手，考虑怎样能牵制对方，其实就是每对里面自己取大的，留给对方小的
成对的取完之后，再从大到小贪心拿
假如自己后手，先跟，跟到对手没拿到成对的，自己就拿成对里面大的，开始反向控制对手，最后再贪心拿
*/

int n, m;
PII against[N], p[N];
bool vis[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i].x;
        p[i].y = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> against[i].x >> against[i].y;
    }
    int t;
    cin >> t;
    if (t == 2) {
        map<int, int> ps;
        for (int i = 1; i <= m; i++) {
            ps[against[i].x] = against[i].y;
            ps[against[i].y] = against[i].x;
        }
        int other;
        int cnt = 0;
        while (true && cnt != 2 * n) {
            cin >> other;
            vis[other] = true;
            cnt++;
            if (ps.count(other)) {
                cout << ps[other] << endl;
                vis[ps[other]] = true;
                cnt++;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = against[i].x, v = against[i].y;
        if (vis[u] || vis[v]) continue;
        int other;
        if (p[u].x > p[v].x) {
            cout << u << endl;
            cin >> other;
            assert(other == v);
        } else {
            cout << v << endl;
            cin >> other;
            assert(other == u);
        }
        vis[u] = true;
        vis[v] = true;
    }
    vector<PII> left;
    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            left.push_back(p[i]);
        }
    }
    sort(left.begin(), left.end());
    reverse(left.begin(), left.end());
    for (int i = 0; i < left.size(); i++) {
        if (!vis[left[i].y]) {
            cout << left[i].y << endl;
            vis[left[i].y] = true;
            int other;
            cin >> other;
            vis[other] = true;
        } 
    }
}
