/*
我们考虑状压 DP
dp[mask] 表示目前已经把 mask 集合里的都吃光，其他的都没吃的概率
枚举上一个被吃的 i，和另一个没被吃的配对，算一下概率
*/ 

const int N = 17;

int n;
double p[N][N];
double dp[1 << N];

int lowbit(int x) {
    return x & -x;
}

int get_cnt(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x -= lowbit(x);
    }
    return cnt;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    dp[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        int cnt = get_cnt(mask);
        for (int i = 0; i < n; i++) {
            if ( (mask >> i) & 1 ) {
                for (int j = 0; j < n; j++) {
                    if ( !((mask >> j) & 1) ) {
                        dp[mask] += dp[mask ^ (1 << i)] * p[j][i] * 1.0 / ((cnt + 1) * cnt / 2);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << setprecision(7) << fixed << dp[((1 << n) - 1) ^ (1 << i)] << "\n";
    }
}
