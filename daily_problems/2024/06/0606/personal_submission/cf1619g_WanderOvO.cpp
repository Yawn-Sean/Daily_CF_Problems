
/*
某个地雷爆炸的时候，和它 k 距离之内的地雷（横纵坐标中有一个相同，另一个差 k 以内）也会爆炸
我们假设第 ans 秒的时候会爆炸完
则我们只需要专注于点那些定时器 > ans 秒的地雷，其他的自生自灭
定时器 > ans 秒的地雷假如有 <= ans + 1 个，则可以逐个点掉，否则需要考虑借助连锁反应
由于 > ans 秒的地雷最后都得爆炸，且都不会自然爆炸，所以我们不用管点击顺序
如何检测连锁反应比较快？
我们无需把所有距离 <= k 的点连边，只需要把相邻的连起来就行
把点按照横纵坐标分别组织起来，然后就可以连边了
*/

struct Mine {
    LL x, y, t, id;
};

int T;
LL n, k;
Mine mines[N];
map<LL, vector<Mine>> row_mines, column_mines;
LL fa[N], min_time[N];

void solve1() {
    cin >> n >> k;
    row_mines.clear();
    column_mines.clear();
    for (int i = 1; i <= n; i++) {
        Mine mine;
        cin >> mine.x >> mine.y >> mine.t;
        mine.id = i;
        mines[i] = mine;
        if (row_mines.count(mine.x)) {
            row_mines[mine.x].pb(mine);
        } else {
            vector<Mine> r;
            r.pb(mine);
            row_mines[mine.x] = r;
        }
        if (column_mines.count(mine.y)) {
            column_mines[mine.y].pb(mine);
        } else {
            vector<Mine> c;
            c.pb(mine);
            column_mines[mine.y] = c;
        }
    }

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        min_time[i] = mines[i].t;
    }

    for (auto &it : row_mines) {
        sort(it.y.begin(), it.y.end(), cmp1);
        int sz = it.y.size();
        for (int i = 0; i < sz - 1; i++) {
            Mine cur = it.y[i], ne = it.y[i + 1];
            if (cur.y + k >= ne.y) {
                merge(cur.id, ne.id);
            }
        }
    }
    for (auto &it : column_mines) {
        sort(it.y.begin(), it.y.end(), cmp2);
        int sz = it.y.size();
        for (int i = 0; i < sz - 1; i++) {
            Mine cur = it.y[i], ne = it.y[i + 1];
            if (cur.x + k >= ne.x) {
                merge(cur.id, ne.id);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int p = find(i);
        if (p != i) {
            min_time[p] = min(min_time[p], min_time[i]);
        }
    }

    vector<LL> block_times;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            block_times.pb(min_time[i]);
        }
    }

    LL cnt = block_times.size();
    sort(block_times.begin(), block_times.end());
    LL res = cnt - 1;
    for (int i = 0; i < cnt; i++) {
        res = min(res, max(block_times[i], cnt - i - 2));
    }
    cout << res << "\n";
}       