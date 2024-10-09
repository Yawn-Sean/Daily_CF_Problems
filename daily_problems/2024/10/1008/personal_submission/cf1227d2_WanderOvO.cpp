/*
包含 k 个数的和最大的子序列，其包含的数其实就是整个数组中最大的 k 个数
如何保证字典序最小？尽量让小的数在前面吧
带着初始位置排序，相等的数则初始位置靠前的在左边
能否按照 k 从小到大的顺序回答询问？
k = 1 时，显然要取最大的数，但是取具体哪个位置的呢？对于 k = 1 的时候倒是无所谓
k = 2 时，需要取次大的数，为了让这个次大的数尽可能靠前，我们肯定得选第一次出现的位置
然后看这个位置右边还有没有最大的数，有的话就还好，没有的话就完蛋了
k = 3 时，也是找第一次出现的位置，然后枚举看这个位置能否是子序列的第一个位置、第二个位置...这样 easy version 就能做了

羊神提示：带着初始顺序排序后的前 k 项按照原顺序排出来就是最小字典序
接下来就好做了，我们直接用权值树状数组标记某个数被选了多少次了
对于每个询问，其实就是找前缀刚好 >= pos 的那个位置，二分+树状数组即可
*/

struct Query {
    int id, k, pos;

    bool operator<(const Query &o) const {
        return k < o.k;
    }
};

int n, m, a[N], res[N];
Query qs[N];
PII c[N];
BIT tr;

bool cmp(const PII &o1, const PII &o2) {
    if (o1.x == o2.x) {
        return o1.y < o2.y;
    }
    return o1.x > o2.x;
}

bool check(int ans, int target) {
    return tr.query(ans) >= target;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i].x = a[i];
        c[i].y = i;
    }
    sort(c + 1, c + n + 1, cmp);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> qs[i].k >> qs[i].pos;
        qs[i].id = i;
    }
    sort(qs + 1, qs + m + 1);
    tr.init(n + 1);
    int query_idx = 1;
    for (int i = 1; i <= n; i++) {
        tr.add(c[i].y, 1);
        for ( ; query_idx <= m && qs[query_idx].k == i; query_idx++) {
            int l = 1, r = n, mid;
            while (l + 1 < r) {
                mid = l + (r - l) / 2;
                if (check(mid, qs[query_idx].pos)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if (check(l, qs[query_idx].pos)) {
                res[qs[query_idx].id] = a[l];
            } else if (check(r, qs[query_idx].pos)) {
                res[qs[query_idx].id] = a[r];
            } else {
                assert(0 == 1);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << "\n";
    }
} 
