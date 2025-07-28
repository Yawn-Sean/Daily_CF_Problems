/*
从终点开始考虑，比如终点是 n，考虑其最少走多少步能到 1
走 1 步能到的位置是一个连续区间，我们要走到哪里呢？
贪心地想，是想走到下一步能到最远的那个位置，即 i - a[i] 最小的那个位置
如果下一步已经可以到 1，则到 1 为止
但是暴力去算上面那个东西的话，可能每次只走 1 步，从而导致复杂度 O(N)
考虑优化，首先是如何快速找能到最远的位置，即查找区间最小，这个只需要 ST 表就可以了
第二个是如何快速模拟走的过程，羊曰这里也可以倍增
我们可以先预处理出从 i 位置开始，走 2^j 步，最多能到哪里，设为 pos[j][i]
pos[0][i] 可以 ST 表+二分求出来
pos[j][i] = pos[j - 1][pos[j - 1][i]]
然后真的模拟时，类似树上 LCA，从大到小枚举 2^j，2^j <= n - 1，如果跳到的位置没越过终点，就跳，否则枚举更小的
如何判断是否越过了终点呢？首先我们先维护一个两倍的链，然后终点是 n + 1 到 2n
那么我们倒着走，起点就应该是 1 到 n，如果走爆了就记为 1
*/

int n, a[N], b[N], nn, pos[M][N], lg[N];
ST st;

void meibao() {
    cin >> n;
    nn = 2 * n;
    for (int i = 2; i <= nn; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= nn; i++) {
        b[i] = max(i - a[i], 1);
    }

    st.init_st(b, nn);

    for (int i = 0; i < M; i++) {
        pos[i][1] = 1;
    }
    for (int i = 2; i <= nn; i++) {
        // i 往左跳，能跳到的再往左跳得最远能到多少
        int mn = st.query(b[i], i - 1);
        mn = max(mn, i - n + 1);
        int l = b[i], r = i - 1, mid;

        auto check = [&] (int ans, int left) -> bool {
            return st.query(left, ans) <= mn;
        };

        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid, b[i])) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check(l, b[i])) {
            pos[0][i] = l;
        } else {
            pos[0][i] = r;
        }
    }

    for (int j = 1; j < M; j++) {
        for (int i = 1; i <= nn; i++) {
            if ((1 << j) <= i) {
                pos[j][i] = pos[j - 1][pos[j - 1][i]];
            }
        }
    }

    LL res = 0;
    for (int i = n; i < nn; i++) {
        int u = i;
        for (int j = lg[n - 1]; j >= 0; j--) {
            if (pos[j][u] > i - n + 1) {
                u = pos[j][u];
                res += (1 << j);
            }
        }
        res += 1;
    }
    cout << res << "\n";
}
