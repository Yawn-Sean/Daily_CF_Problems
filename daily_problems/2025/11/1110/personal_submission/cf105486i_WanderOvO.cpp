/*
考虑所有满足 a[i] > a[i + 1] 的 i
我们要选择的 k，需要满足是这些 i 的因数才行
每单点修改 i 位置的数，会导致 i - 1 位置或者 i 位置变成上述的 i
我们相当于是要求出来这些位置的 gcd，然后求这个 gcd 的因数个数
如何求这些位置的 gcd？可以用线段树维护区间 gcd，每次相当于单点修改，以及查根结点的 gcd
如果要根号求因数，可能会爆掉，所以考虑素因数分解之后，把因数组合出来，类似前几天题目的做法
只不过，这里无需组合出来具体的因数，只需要利用乘法原理算出个数就好了
*/ 
 
struct SegmentTree {
    LL tr[4 * N], n;
 
    LL gcd(LL a, LL b) {
        return b == 0 ? a : gcd(b, a % b);
    }
 
    void pushup(int k) {
        tr[k] = gcd(tr[ls], tr[rs]);
    }
 
    void modify(int l, int r, int k, int pos, LL val) {
        if (l == r) {
            tr[k] = val;
            return;
        }
 
        int mid = (l + r) / 2;
        if (pos <= mid) {
            modify(l, mid, ls, pos, val);
        } else {
            modify(mid + 1, r, rs, pos, val);
        }
        pushup(k);
    }
 
    LL query() {
        return tr[1];
    }
 
    void init(int sz) {
        n = sz;
        for (int i = 0; i <= 4 * n; i++) {
            tr[i] = 0;
        }
    }
};
 
SegmentTree smt;
LL n, q, a[N], primes[N], cnt;
bool is_prime[N];
 
void meibao() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    smt.init(n);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            smt.modify(1, n, 1, i, i);
        }
    }
 
    auto calc = [&] (LL val) -> LL {
        if (val == 0) {
            return n;
        }
        LL root = sqrt(val);
        LL res = 1;
        for (int i = 0; i < cnt && primes[i] <= root; i++) {
            if (val % primes[i] == 0) {
                LL cnt = 0;
                while (val % primes[i] == 0) {
                    val /= primes[i];
                    cnt++;
                }
                res *= (cnt + 1);
            }
        }
        if (val > 1) {
            res *= 2;
        }
        return res;
    };
 
    cout << calc(smt.query()) << "\n";
 
    while (q--) {
        LL p, v;
        cin >> p >> v;
        a[p] = v;
        if (p - 1 > 0) {
            if (a[p - 1] > a[p]) {
                smt.modify(1, n, 1, p - 1, p - 1);
            } else {
                smt.modify(1, n, 1, p - 1, 0);
            }
        }
        if (p + 1 <= n) {
            if (a[p] > a[p + 1]) {
                smt.modify(1, n, 1, p, p);
            } else {
                smt.modify(1, n, 1, p, 0);
            }
        }
 
        cout << calc(smt.query()) << "\n";
    }
}   
    
void prepare() {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}
