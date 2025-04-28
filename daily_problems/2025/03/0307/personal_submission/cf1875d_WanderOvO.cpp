/*
考虑先删除完一个数字之后，删除完剩下所有数字的最小代价
dp[i]: i 已经被删除完了，再把剩下的数删除的最小代价
肯定是删了大的之后删小的
dp[i] = dp[j] + (cnt[j] - 1) * i + j
*/
 
int T;
LL a[N], n, dp[N], cnt[N];
 
void solve1() {
    cin >> n;
    LL mex = 0;
    set<LL> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        if (a[i] == mex) {
            for (int j = mex; ; j++) {
                if (!s.count(j)) {
                    mex = j;
                    break;
                }
            }
        }
    }
    
    if (mex == 0) {
        cout << "0\n";
        return;
    }
    
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= mex) {
            cnt[a[i]]++;
        }
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = min(dp[i], dp[j] + (cnt[j] - 1) * i + j);
        }
    }
    LL res = (n + 1) * n;
    for (int i = 0; i <= n; i++) {
        res = min(res, dp[i] + (cnt[i] - 1) * mex + i);
    }
    cout << res << "\n";
}            
