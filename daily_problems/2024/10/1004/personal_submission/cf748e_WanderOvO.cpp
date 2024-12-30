/*
一个橘子可以被平分成两部分，或者分成差 1 片的两部分
每个部分也可以再切开
对于每个人，可以给它一个完整的橘子，也可以给其中一部分，最大化最小的片数
显然可以二分答案
对于每个答案 ans，对每个橘子二分做拆分，看至多能拆出多少个符合题意的块来
橘子的片数 <= 1e7，可以考虑使用 DP，计算片数为 i 的橘子至多能分出多少个合法的块来
*/

LL n, k, a[N];
LL dp[M];

bool check(int ans) {
    for (int i = 0; i < M; i++) {
        dp[i] = -1;
    }
    for (int i = 0; i < ans; i++) {
        dp[i] = 0;
    }
    for (int i = ans; i < M; i++) {
        if (i % 2 == 0) {
            dp[i] = max(dp[i / 2] * 2, 1LL);
        } else {
            int half = i / 2;
            dp[i] = max(dp[half] + dp[half + 1], 1LL);
        }
    }
    LL tot_slices = 0;
    for (int i = 1; i <= n; i++) {
        tot_slices += dp[a[i]];
    }
    return tot_slices >= k;
}

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    int l = 0, r = 1e7, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int res = check(r) ? r : l;
    if (res == 0) {
        cout << "-1\n";
    } else {
        cout << res << "\n";
    }
}       
