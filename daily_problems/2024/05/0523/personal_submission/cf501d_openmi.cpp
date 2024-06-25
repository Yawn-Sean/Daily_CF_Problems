const int MAXN = 2e5+10;
ll ftr1[MAXN + 10] = {0};
ll ftr2[MAXN + 10] = {0};
ll ftr3[MAXN + 10] = {0};
int n;
ll get(ll* f, int x)
{
    ll ret = 0;
    x++;
    for (; x; x -= x & -x) ret += f[x];
    return ret;
}

void add(ll* f, int x, int p)
{
    x++;
    for (; x <= n; x += x & -x) f[x] += p;
}

ll findKth(ll* f, int target) {
    int bitMask = 1 << (31 - __builtin_clz(n)); 
    int idx = 0; 
    while (bitMask) {
        int tmp = idx + bitMask;
        if (tmp <= n and f[tmp] <= target) {
            idx = tmp;
            target -= f[tmp];
        }
        bitMask >>= 1;
    }
    return idx;
}

void solve() {
    cin >> n;
    vi perm1(n + 1), perm2(n + 1), ord1(n + 1), ord2(n + 1);

    int x;
    rb (i, 1, n) {
        cin >> x;
        perm1[i] = x;
        ord1[i] = x - get(ftr1, x);
        add(ftr1, x, 1);
    }
    
    rb (i, 1, n) {
        cin >> x;
        perm2[i] = x;
        ord2[i] = x - get(ftr2, x);
        add(ftr2, x, 1);
    }

    int nxt = 0, cur, curm;
    vi ord3(n + 1);
    br(i, n, 1) {
        cur = ord1[i] + ord2[i] + nxt;
        curm = n - i;
        nxt = cur > curm;
        if (curm) ord3[i] = cur % (curm + 1);
    }
    rb (i, 1, n) add(ftr3, i, 1);
    rb (i, 1, n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (get(ftr3, m) < ord3[i]) l = m + 1;
            else r = m;
        }
        cout << r << ' ';
        add(ftr3, r, -1);
        // 树状数组上二分
        // cur = findKth(ftr3, ord3[i]);
        // cout << cur - 1 << ' ';
        // add(ftr3, cur, -1);
    }
}
