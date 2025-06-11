/*
总球数不多，看可以枚举什么东西，或者 DP
前两轮保证 A 都大于 B，看一下不同差值的情况下有多少方案
先只看一轮，算一下第 1 个球比第 2 个球大 j 的方案数有多少，需要 O(n^2)
然后第一轮的情况自行组合一下，就出来了第二轮的方案数，需要 O(max(a)^2)
第二轮的结果应该至多有 O(2 * max(a)) 个状态
我们再 O(n^2) 枚举第三轮的方案，算一下差值，看能和第二轮的哪些状态匹配上
*/

int T;
LL cnt[3][M], n, a[N], pre_sum[M];

void solve1() {
    cin >> n;
    LL max_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cnt[1][a[i] - a[j]]++;
        }
    }
    for (int i = 1; i <= max_a; i++) {
        for (int j = 1; j <= max_a; j++) {
            cnt[2][i + j] += cnt[1][i] * cnt[1][j]; 
        }
    }
    for (int i = 1; i <= 2 * max_a; i++) {
        pre_sum[i] = pre_sum[i - 1] + cnt[2][i];
        // cout << pre_sum[i] << ' ';
    }
    // cout << "\n";

    LL valid_cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            LL d = a[j] - a[i];
            valid_cnt += pre_sum[d - 1];
        }
    }
    // cout << valid_cnt << "\n";
    double res = (1.0 * valid_cnt) / pow((n * (n - 1)) / 2, 3);
    cout << setprecision(12) << res << "\n";
}     
