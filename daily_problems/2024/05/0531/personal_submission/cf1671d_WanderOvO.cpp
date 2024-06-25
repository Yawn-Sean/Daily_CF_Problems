/*
容易发现，假如在 a[i] 和 a[i + 1] 中插入一个大小介于二者之间的数，则和不变
如果不介于二者之间，则和一定会变大
我们考虑所有相邻的 a[i] 和 a[i + 1]，把能填的数都塞进去，看一下能否用完 1-x
分析一下，假设 a 中原本最小值是 mn，最大值是 mx
则我们一定有办法把 [1, x] 中的 [mn, mx] 都无代价插入进去
所以我们只需要考虑 [1, mn - 1] 和 [mx + 1, x] 之间的数怎么插代价最小
由于 [1, mn - 1] 中的数都严格小于 a 中的最小值，[mx + 1, x] 中的数严格大于最大值
所以本质上就是看 1 和 x 插到哪里代价最小
我们考虑把 1 和 x 插到不同的位置，能得到一个最优的方案
再考虑 1 和 x 放到一起，也可以得到一个最优方案
比较一下哪个更好（其实 1 和 x 放到一起肯定不如分开更优）
*/

int T;
LL a[N], n, x;

void solve1() {
    cin >> n >> x;
    LL min_a = INF, max_a = -INF;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        min_a = min(min_a, a[i]);
        max_a = max(max_a, a[i]);
        if (i >= 2) {
            res += abs(a[i] - a[i - 1]);
        }
    }
    
    LL min_cost1 = INF, min_costx = INF;
    if (min_a == 1) {
        min_cost1 = 0;
    } 
    if (max_a >= x) {
        min_costx = 0;
    }

    for (int i = 2; i <= n; i++) {
        LL cost1 = abs(a[i] - 1) + abs(a[i - 1] - 1) - abs(a[i] - a[i - 1]);
        LL costx = abs(a[i] - x) + abs(a[i - 1] - x) - abs(a[i] - a[i - 1]);
        min_cost1 = min(min_cost1, cost1);
        min_costx = min(min_costx, costx);
    }
    min_cost1 = min({min_cost1, (LL)abs(a[1] - 1), (LL)abs(a[n] - 1)});
    min_costx = min({min_costx, (LL)abs(a[1] - x), (LL)abs(a[n] - x)});
    res += min_cost1 + min_costx;
    cout << res << "\n";
}            