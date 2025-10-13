/*
首先显然是预处理出对于 a[i] 来说满足条件的区间的左右边界
注意，有重复元素，并且根据题意，我们是要重复算那一部分的，所以要找到严格比自己大的再停
求出区间左右端点之后，我们考虑 f(i) 中，每个数贡献了多少次
假设区间是 [l, r]，l <= i <= r
a[l] 在计算 f(i) 时贡献了多少次？r - i + 1 次
a[j](j < i) 贡献了多少次？(j - l + 1) * (r - i + 1) 次
a[j](j > i) 贡献了多少次？(i - l + 1) * (r - j + 1) 次
这两个都是等差数列，可以用二阶差分快速维护
每个位置的贡献次数算出来之后，遍历一遍求和就好了
*/ 

LL n, a[N];
LL d2[N], l[N], r[N];
const int mod = 1e9 + 7;

void add(LL l, LL r, LL st, LL d) {
    st %= mod;
    d %= mod;
    d2[l] += st;
    d2[l] %= mod;
    d2[l + 1] -= st;
    d2[l + 1] %= mod;

    d2[l + 1] += d;
    d2[r + 1] -= d;
    d2[l + 1] %= mod;
    d2[r + 1] %= mod;

    d2[r + 1] -= (st + d * (r - l) % mod) % mod;
    d2[r + 2] += (st + d * (r - l) % mod) % mod;
    
    d2[r + 1] %= mod;
    d2[r + 2] %= mod;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        l[i] = 1;
        r[i] = n;
    }
    vector<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            r[stk.back()] = i - 1;
            stk.pop_back();
        } 
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n; i > 0; i--) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            l[stk.back()] = i + 1;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        add(l[i], i, r[i] - i + 1, r[i] - i + 1);
        if (r[i] > i) {
            add(i + 1, r[i], (i - l[i] + 1) * (r[i] - i), -(i - l[i] + 1));
        }
    }

    for (int i = 1; i <= n; i++) {
        d2[i] += d2[i - 1];
        d2[i] %= mod;
    }
    for (int i = 1; i <= n; i++) {
        d2[i] += d2[i - 1];
        d2[i] %= mod;
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += a[i] * d2[i] % mod;
        res %= mod;
    }
    res = (res % mod + mod) % mod;
    cout << res << endl;
}   
