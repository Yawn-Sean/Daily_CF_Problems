/*
参考洛谷的翻译
修复之前，每天只能生产 b，修复之后恢复到生产 a 的水平
单点增加，区间取 min 后求和
维护两棵线段树，一棵是对 b 取 min，一棵对 a 取 min
单点修改到底，至多加到临界值
查询时，只要在第一颗线段树中查前缀，第二颗线段树中查后缀即可
*/

SegmentTree pre, suf;
LL n, k, a, b, q;

void meibao() {
    cin >> n >> k >> a >> b >> q;
    pre.init(n, b);
    suf.init(n, a);
    while (q--) {
        LL op;
        cin >> op;
        if (op == 1) {
            LL pos, val;
            cin >> pos >> val;
            pre.modify(1, n, pos, val, 1);
            suf.modify(1, n, pos, val, 1);
        } else {
            LL pos;
            cin >> pos;
            LL res = 0;
            if (pos - 1 > 0) {
                res += pre.query(1, n, 1, pos - 1, 1);
            }
            if (pos + k <= n) {
                res += suf.query(1, n, pos + k, n, 1);
            }
            cout << res << "\n";
        }
    }
}
