int n;
LL a[N];
LL pre[N];
LL p2[N]; 

LL get_ways(int len) {
    if (len == 0) return 1;
    if (len < 0) return 0; 
    return p2[len - 1];
}

void solve() {
    cin >> n;
    
    pre[0] = 0;
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        p2[i] = (p2[i-1] * 2) % MOD;
    }

    LL total_sum = pre[n];
    LL limit = (total_sum + 1) / 2;
    
    LL bad_ways = 0;
    LL sum_left_weights = 0; 
    int ptr = 0; 

    for (int j = 1; j <= n; j++) {
        LL threshold = pre[j] - limit;

        while (ptr < j && pre[ptr] <= threshold) {
            LL w = (ptr == 0) ? 1 : p2[ptr - 1];
            sum_left_weights = (sum_left_weights + w) % MOD;
            ptr++;
        }

        LL right_w = (j == n) ? 1 : p2[n - j - 1];
        
        LL term = (sum_left_weights * right_w) % MOD;
        bad_ways = (bad_ways + term) % MOD;
    }

    LL total_ways = (n == 0) ? 0 : p2[n - 1];
    LL ans = (total_ways - bad_ways + MOD) % MOD;

    if (total_sum % 2 == 0) {
        LL half = total_sum / 2;
        int idx = lower_bound(pre + 1, pre + n + 1, half) - pre;
        if (idx <= n && pre[idx] == half) {
            ans = (ans + 1) % MOD;
        }
    }

    cout << ans << endl;
}
