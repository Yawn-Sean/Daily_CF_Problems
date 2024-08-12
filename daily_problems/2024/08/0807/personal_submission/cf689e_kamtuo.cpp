const int MOD = 1000000007;
typedef long long LL;

LL fastpower(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    } 
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1, 0), y(n + 1, 0), s(n << 4, 0), p(n + 1, 0), inv(n + 1, 0);
    p[0] = inv[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p[i] = 1ll * p[i - 1] * i % MOD;
        inv[i] = fastpower(p[i], MOD - 2); 
    }
    vector<int> nums, cnt;
    nums.push_back(-1000000000);
    nums.push_back(1000000000);
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        nums.push_back(x[i]);
        nums.push_back(y[i]);
    }
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    for (int i = 0; i < len; i ++) {
        cnt.push_back(1);
        if (i != len - 1 && nums[i + 1] != nums[i] + 1) cnt.push_back(nums[i + 1] - nums[i] - 1), nums.push_back(nums[i] + 1); 
    }
    sort(nums.begin(), nums.end());
    len = unique(nums.begin(), nums.end()) - nums.begin();
    std::function<int (int)> find = [&] (int x) -> int {
        return lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin();
    };
    std::function<int (int, int)> C = [&] (int n, int m) -> int {
        return 1ll * p[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    for (int i = 1; i <= n; i ++) {
        int fx = find(x[i]) + 1, fy = find(y[i]) + 1;
        s[fx] ++;
        s[fy + 1] --;
    }
    for (int i = 1; i <= len; i ++) s[i] += s[i - 1], s[i] %= MOD;
    long long ans = 0;
    for (int i = 1; i <= len; i ++) {
        if (s[i] >= k) ans = ans + 1ll * C(s[i], k) % MOD * cnt[i - 1] % MOD;
        ans %= MOD; 
    }
    cout << ans << endl;
    return 0;
}
