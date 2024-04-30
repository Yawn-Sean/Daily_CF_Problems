/*
看起来答案比较受制于最小的那个
假如种类 i 出现次数最少，为 cnt[i]，则每个窗口最大只可能是 cnt[i] + 1
然后我们要验证答案是否符合题意
假设当前窗口大小是 m，j 出现了 cnt[j] 次，则 cnt[j] / m + cnt[j] % m >= m - 1 才能行
复杂度其实是 O(a * n / a)，为 O(n) 的
*/

int T;
int cc[N], n;
vector<int> cnt;

bool check(int m) {
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] % m != 0) {
            int c = cnt[i] / m;
            int r = cnt[i] % m;
            if (c + r < m - 1) {
                return false;
            }
        }
    }
    return true;
} 

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cc[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cc[x]++;
    }
    cnt.clear();
    for (int i = 1; i <= n; i++) {
        if (cc[i] > 0) {
            cnt.pb(cc[i]);
        }
    }
    int mn = n;
    for (int i = 1; i <= n; i++) {
        if (cc[i] > 0) {
            mn = min(mn, cc[i]);
        }
    }
    
    int res = n;
    
    for (int i = 1; i <= mn + 1; i++) {
        int m = i;
        if (check(m)) {
            int ans = 0;
            for (int j = 0; j < cnt.size(); j++) {
                ans += (cnt[j] + m - 1) / m;
            }
            res = min(res, ans);
        }
    }
    cout << res << "\n";
}   