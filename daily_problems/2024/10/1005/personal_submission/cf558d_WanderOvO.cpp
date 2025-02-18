/*
h 层的完美二叉树有 2^h - 1 个结点
问 exit 在第 i 层的父亲的结点编号是否在 [L, R] 之间
如果在，则第 i + 1 层的父亲结点一定在 [2 * L, 2 * R + 1] 之间
我们按照深度从小到大的顺序去考虑每次询问，这样可以逐渐缩小搜索区间，最后看是否能唯一确定
发现好像回答为 0 时会出现待搜索区间碎成很多块的情况，不好处理
考虑把所有条件统一看待，如果是 1 则把对应区间染色，如果是 0 则把对应区间之外的部分染色
最后看有多少个点满足被染色了 q 次即可
*/

struct Question {
    LL level, L, R, ans;

    bool operator<(const Question &o) const {
        return level < o.level;
    }
};

LL h, q;
Question questions[N];

void meibao() {
    cin >> h >> q;
    for (int i = 1; i <= q; i++) {
        cin >> questions[i].level >> questions[i].L >> questions[i].R >> questions[i].ans;
    }
    if (h == 1 && q == 0) {
        cout << "1";
        return;
    }
    map<LL, LL> d;
    LL down = (1LL << (h - 1)), up = (1LL << h) - 1;
    for (int i = 1; i <= q; i++) {
        LL l = questions[i].L, r = questions[i].R;
        LL cur_level = questions[i].level;
        while (cur_level < h) {
            cur_level++;
            l *= 2;
            r *= 2;
            r++;
        }
        if (questions[i].ans == 1) {
            d[l]++;
            d[r + 1]--;
        } else {
            d[down]++;
            d[l]--;
            d[r + 1]++;
            d[up + 1]--;
        }
    }
    LL cnt = 0;
    LL s = 0, last = down - 1, res = 0;
    for (auto &it : d) {
        if (s == q) {
            cnt += it.x - last;
            res = last;
        }
        s += it.y;
        last = it.x;
    }
    if (cnt == 0) {
        cout << "Game cheated!";
    } else if (cnt > 1) {
        cout << "Data not sufficient!";
    } else {
        cout << res;
    }
}   
