/*
9998 9999, 1
9999 0, -9999

9999 3, -9996
0 4, 4
位移要求还要最小，这个要考虑到
必要条件：
- abs(子串首项 - 目标首项) <= 9999，这个无条件就保证了，无需在意
- 公差逐项相等，或差 10000
首项已经决定了要加多少了，只可能有这一种方案，因为绕一圈必定 >= 10000
1 9999 3, 9998 -9996
2 0 4, -2 4
我们把差分数组取模成正数，然后相当于每次只需判断子串是否相等
*/

struct MyHash {
    LL P, mod, p[N], h[N];
    
    void init(LL a[], int n, int _P, int _mod) {
        p[0] = 1;
        P = _P;
        mod = _mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P % mod;
            h[i] = h[i - 1] * P + a[i];
            h[i] %= mod;
        }
    }
    
    LL get(int l, int r) {
        return ((h[r] - h[l - 1] * p[r - l + 1] % mod) % mod + mod) % mod; 
    }
};

LL n, m, a[N], b[N], da[N], db[N];
MyHash ha1, ha2, hb1, hb2;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        da[i] = (a[i] - a[i - 1] + 10000) % 10000;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        db[i] = (b[i] - b[i - 1] + 10000) % 10000;
    }
    
    int P = 13331;
    int mod1 = 998244853, mod2 = 1e9 + 7;
    ha1.init(da, n, P, mod1);
    ha2.init(da, n, P, mod2);
    hb1.init(db, m, P, mod1);
    hb2.init(db, m, P, mod2);
    
    map<int, int> cnt;
    for (int i = 1; i + m - 1 <= n; i++) {
        int c;
        if (b[i] >= a[i]) {
            c = b[i] - a[i];
        } else {
            c = 10000 + b[i] - a[i];
        }
        if (ha1.get(i + 1, i + m - 1) == hb1.get(2, m)
            && ha2.get(i + 1, i + m - 1) == hb2.get(2, m)) {
            cnt[c]++;    
        }
    }
    
    int min_cost = 1e5, max_cnt = 0;
    for (auto &it : cnt) {
        if (it.second > max_cnt) {
            max_cnt = it.second;
            min_cost = it.first;
        } else if (it.second == max_cnt) {
            if (it.first < min_cost) {
                min_cost = it.first;
            }
        }
    }
    if (max_cnt == 0) {
        min_cost = 0;
    }
    cout << min_cost << " " << max_cnt << "\n";
}
