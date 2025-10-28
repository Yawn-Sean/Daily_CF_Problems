/*
我们考虑将 b[1...n] 变成目标数列，其中第一个数是 x
则总的代价是 sum(abs(b[i] - (x + i - 1))) = sum(abs(b[i] - i + 1 - x))
我们是想最小化这个东西，即确定一个 x
令 c[i] = b[i] - i + 1，则就是求 sum(abs(c[i] - x))
显然是取 x 为 c[i] 的中位数会代价最小

如果是 a[l...r]，第一个数是 x
则总代价是 sum(abs(a[i] - (x + i - l))) = sum(abs(a[i] - i + l - x))
b[i] = a[i] - i + l，则最小化 sum(abs(b[i] - x))，取 b[i] 的中位数
每个数都 + l 了，不妨每个数都不加，这是不影响 sum 的结果的

假如我们能把 len 长度的变成目标数列，则更短的肯定也行，所以有单调性
考虑二分答案，然后检查每个答案是否符合题意
如何检查？假设答案是 ans，则我们要看连续的 ans 个数里面的中位数
其实就是看 a[i] - i 的中位数，需要动态维护，并且带删除的
可以使用权值树状数组去查中位数是谁，只要求排名 >= (ans + 1) / 2 的最小的数就好了，不用管奇偶和并列
求出中位数还不够，还得求到底要变多少次，这个如何快速计算？
假设中位数是 x，则对于 <= x 的数，需要求 x - 这些数
对于 > x 的数，要求这些数 - x
所以还要用另一个树状数组，维护一下和
二分的 log + 树状数组的 log，比较危险，把二分改成双指针就好了
*/

struct Fenwick {
    LL tr[N], n;
    
    int lowbit(int x) {
        return x & -x;
    }  
    
    void init(int sz) {
        n = sz;
        for (int i = 0; i <= n; i++) {
            tr[i] = 0;
        }
    }
    
    void modify(LL pos, LL val) {
        while (pos <= n) {
            tr[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    LL query(LL pos) {
        LL res = 0;
        while (pos) {
            res += tr[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    LL lower_bound(LL target) {
        int pos = 0;
        int st = log2(n);
        for (int i = st; i >= 0; i--) {
            int next_pos = pos + (1 << i);
            if (next_pos > n) continue;
            if (tr[next_pos] < target) {
                target -= tr[next_pos];
                pos = next_pos;
            }
        }
        return pos + 1;
    }
};

LL n, k, a[N], b[N], c[N];
Fenwick rk, sum;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    
    sort(b + 1, b + n + 1);
    
    for (int i = 1; i <= n; i++) {
        c[i] = lower_bound(b + 1, b + n + 1, a[i] - i) - b;
    }
    
    rk.init(n);
    sum.init(n);

    int l = 1, r = 1;
    int res = 1;
    while (r <= n) {
        rk.modify(c[r], 1);
        sum.modify(c[r], a[r] - r);

        while (l <= r) {
            int ans = r - l + 1;
            int pos = rk.lower_bound((ans + 1) / 2);
            LL less_cnt = rk.query(pos);
            LL more_cnt = ans - less_cnt;
            LL x = b[pos];
            LL cost = less_cnt * x - sum.query(pos) + sum.query(n) - sum.query(pos) - more_cnt * x;
            if (cost <= k) {
                res = max(res, r - l + 1);
                break;
            }
            rk.modify(c[l], -1);
            sum.modify(c[l], l - a[l]);
            l++;
        }

        r++;
    }
    cout << res << "\n";
}
