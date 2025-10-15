/*
类似扫描线，先把每个区间的左端点和右端点 + 1预处理出来，按照从小到大存一下
枚举每一天，然后更新新增的计划，删除过期的计划
新增计划时，在其单价 p[i] 位置增加 c[i] 个物品，并增加 p[i] * c[i] 的总价值
使用树状数组二分，二分出买到哪个价格的物品，然后再补最后一个的
*/

struct Operation {
    LL x, c, p, op;

    bool operator<(const Operation &o) const {
        return x < o.x;
    }
};

vector<Operation> ops;
int n, k, m;
BIT cnt, sum;

void meibao() {
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        ops.push_back({l, c, p, 1});
        ops.push_back({r + 1, c, p, -1});
    }

    sort(ops.begin(), ops.end());

    int pt = 0;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        while (pt < ops.size() && ops[pt].x == i) {
            LL x = ops[pt].x, c = ops[pt].c, p = ops[pt].p, op = ops[pt].op;
            cnt.add(p, c * op);
            sum.add(p, c * p * op);
            pt++;
        }

        LL id = cnt.binary_search(k);
        LL cost = sum.query(id);
        LL left_cnt = k - cnt.query(id);
        if (left_cnt > 0) {
            if (id + 1 <= N - 1) {
                id++;
                cost += left_cnt * id;
            }
        }

        res += cost;
    }
    cout << res << "\n";
}
