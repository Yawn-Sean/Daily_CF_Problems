/*
类似前段时间某道 div3
求恰好 = k 是困难的，但是求 <= k 是简单的，所以只要求 <= k 和 <= k - 1 的即可
如何求？
我们注意到，在原来区间的基础上增加一个元素，异或 min 不会变大，减少一个元素，异或 min 不会变小
考虑枚举区间右端点，然后满足区间内最小异或对 <= k 的左端点一定是某个前缀
我们其实关心，对于每个 a[i]，考虑左边和自己最近的 a[j]，使得 a[i] ^ a[j] <= k
如果能预处理出这个值，则考虑 [l, r] 是否可行时，只要看 [l, r] 这段里这个值的 max 是否 >= l 就好了
其实，在求右端点为 r 的区间有多少个时，右端点为 r - 1 的区间个数已经知道了
也就是说，r - 1 对应的最大的 l 已经知道了
那么对于 r 来说，其最大的左端点一定 >= l
所以，我们只需要考虑 a[r] 和 [l, r - 1] 里面的哪个数异或起来最小，并看其是否 <= k
假如 > k，则左端点依然是 l
假如 <= k，则左端点就可以尝试右移一下，再 check 一下
直到 check 得不行了，则左端点就是最后一次 check 还行的那个值
*/

LL tr[M * N][2], cnt[M * N], n, k;
LL a[N], idx = 1;

void insert(LL val) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (!tr[p][ch]) {
            tr[p][ch] = ++idx;
        }
        p = tr[p][ch];
        cnt[p]++;
    }
}

void del(LL val) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        p = tr[p][ch];
        cnt[p]--;
    }
}

LL query(LL val) {
    LL res = 0;
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (tr[p][ch]) {
            if (cnt[tr[p][ch]]) {
                res *= 2;
                p = tr[p][ch];
            } else {
                res = 2 * res + 1;
                p = tr[p][ch ^ 1];
            }
        } else {
            res = 2 * res + 1;
            p = tr[p][ch ^ 1];
        }
    }
    return res;
}

void solve() {   
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    insert(a[1]);
    int l = 0;
    LL res1 = 0, res2 = 0;
    for (int i = 2; i <= n; i++) {
        while (l + 1 <= i) {
            LL val = query(i);
            if (val <= k) {
                l++;
            } else {
                break;
            }
        }
        
        res1 += l;
        insert(a[i]);
    }
    
    memset(cnt, 0, sizeof cnt);
    memset(tr, 0, sizeof tr);
    idx = 1;
    insert(a[1]);
    l = 0;
    for (int i = 2; i <= n; i++) {
        while (l + 1 <= i) {
            LL val = query(i);
            if (val < k) {
                l++;
            } else {
                break;
            }
        }
        
        res2 += l;
        insert(a[i]);
    }
    cout << res1 - res2 << "\n";
}
