/*
假设旋转了 k 个单位，怎么判断其是否和原图相同？
旋转 k 个单位，相当于所有点的编号 + k（调整一下 n 到 1 的情况）
然后只要比较是否相同就好了，最好是按照某个顺序排个序
但其实可以强行哈希一下，强制让小的端点在前，大的在后，算一个哈希值，新的也算哈希值，看看是否出现过即可

如何较少地枚举需要旋转几个单位，或者能够较快地判断是否和原图相同？
羊神提示：假设旋转 x 个单位后一样，则旋转 kx 个单位后也一样
由于旋转 n 个单位等于没旋转，所以旋转 kx % n 个单位也一样
设 kx % n = m，则考虑 an + kx = m，其中 n, x 是确定的，只要 m % gcd(n, x) == 0，则能求出整数解 (a, k)
m = gcd(n, x) 时，是最小的变化元 
如何求 m？其实就是求 gcd(n, x)
gcd(n, x) 可能有多少种情况呢，其实能取的值就是 n 的所有约数
我们枚举 n 的所有约数（除了 n 自己），然后使用上面的方法去判断即可
*/

int T;
LL n, m;
vector<PLL> segs(N);
unordered_set<LL> h;

bool check(LL x) {
    for (int i = 1; i <= m; i++) {
        LL l = segs[i].x, r = segs[i].y;
        l += x;
        r += x;
        if (l > n) {
            l -= n;
        }
        if (r > n) {
            r -= n;
        }
        if (l > r) {
            swap(l, r);
        }
        if (!h.count((n + 1) * l + r)) {
            return false;
        }
    }
    return true;
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> segs[i].x >> segs[i].y;
        if (segs[i].x > segs[i].y) {
            swap(segs[i].x, segs[i].y);
        }
        h.insert((n + 1) * segs[i].x + segs[i].y);
    }
    vector<int> factors;
    int root = sqrt(n);
    for (int i = 1; i <= root; i++) {
        if (n % i == 0) {
            factors.pb(i);
            int another = n / i;
            if (another != n && another != i) {
                factors.pb(another);
            }
        }
    }
    bool ok = false;
    for (auto factor : factors) {
        ok |= check(factor);
    }
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}     