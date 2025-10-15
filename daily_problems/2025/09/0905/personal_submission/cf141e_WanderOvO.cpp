/*
需要求一棵生成树，其有一半的边颜色是 S，另外一半的边颜色是 M
n = 1e3, m = 1e5
n 为偶数时，一定无解
n 为奇数时，不妨 S 标为 1，M 标为 0，则相当于找一个权重之和为 (n - 1) / 2 的生成树
点数不多，边数很多，暗示了什么样的做法？
能否先选好某种类型的边，然后判断能否用另一种类型的边使得整个图连通起来，且没有环
或者选一个 0，紧接着选一个 1，如果选了成环就不能选
能否先求一个最小生成树，假如最小生成树的权值大于一半了肯定就废了
假如最小生成树权值小于一半，则考虑枚举其他的权值为 1 的边，将其加进来，然后替换某条长度为 0 的边
替换这个事情是否总能做到？并不一定，因为有可能加了某条边之后得到的那个环上全是 1
n 很小，我们好像又可以暴力去枚举替换哪条边了
具体来说，我们优先用刚选的那条为 1 的边，以及之前选的为 1 的边，之后再用之前选的为 0 的边
如果最后依然能得到一棵树，就说明这种替换是可行的
有没有可能边的替换顺序影响答案？即我选了某条为 1 的边，替换掉某个 0 边之后，再加入 1 边，就只会出现 1 环了？

羊神提示：有一些边是必须选的
我们先强制把**所有的** M 边都选上，然后看还要选哪些 S 边，才能让全图连通，则这些 S 边是必选的
然后我们再选一些 S 边，凑够一半且不成环
最后我们选 M 边，再把整个图尝试连成一棵树

我的做法里，先求了 MST，相当于尽力选 M，实在不行再选 S，同样可以得到必选的 S 边
*/

struct Edge {
    int u, v, w, id;

    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

int n, m, fa[N];
bool choose[N];
Edge es[N];

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w = 0, id;
        string s;
        cin >> u >> v >> s;
        id = i;
        if (s == "S") {
            w = 1;
        } 
        es[i] = {u, v, w, id};
    }

    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }

    sort(es + 1, es + m + 1);

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int u = es[i].u, v = es[i].v, w = es[i].w, id = es[i].id;
        if (!together(u, v)) {
            sum += w;
            merge(u, v);
            choose[i] = true;
        }
    }

    if (sum > (n - 1) / 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    sum = 0;
    int choose_cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (choose[i]) {
            if (es[i].w == 0) {
                choose[i] = false;
            } else {
                merge(es[i].u, es[i].v);
                sum++;
                choose_cnt++;
            }
        }
    }

    for (int i = 1; i <= m && sum < (n - 1) / 2; i++) {
        if (!choose[i] && es[i].w == 1) {
            if (!together(es[i].u, es[i].v)) {
                merge(es[i].u, es[i].v);
                sum++;
                choose_cnt++;
                choose[i] = true;
            }
        }
    }

    if (sum != (n - 1) / 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= m; i++) {
        if (!choose[i] && es[i].w == 0) {
            if (!together(es[i].u, es[i].v)) {
                merge(es[i].u, es[i].v);
                choose_cnt++;
                choose[i] = true;
            }
        }
    }

    if (choose_cnt == n - 1) {
        cout << n - 1 << "\n";
        for (int i = 1; i <= m; i++) {
            if (choose[i]) {
                cout << es[i].id << " ";
            }
        }
    } else {
        cout << "-1\n";
    }
}
