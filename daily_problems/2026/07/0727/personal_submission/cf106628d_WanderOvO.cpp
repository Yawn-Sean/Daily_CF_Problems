/*
考虑一个确定的 k 子集
奇数 - 偶数 = 1，这个是最小的连接代价
所以可以用一个奇数，把所有偶数拼成一个菊花图
或者用一个偶数，把所有奇数拼成一个菊花图
对于剩下的数，他们的最低位都相同了，就只能最低以 2 的代价连接了
卧槽我好像 sb 了
假如同时存在奇数和偶数，我们就用一个奇数把所有偶数串起来
再把剩下的奇数挂在偶数上就好了
如果都是奇数或者都是偶数
或者更一般的，所有数从第 i 位开始才有不一样的，i 从 0 开始
那么 MST 的代价就是 (n - 1) * 2^i
我们好像就是需要找 k 个数，使得二进制表示的最长公共后缀最长
这个事情大概可以这样维护
我们钦定至少后 i 位必须一样
然后按照后 i 位对所有数进行分组，但凡有一个组的大小 >= k，那就赢了
*/ 

const int N = 2e5 + 10;

LL n, k, a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    LL res = k - 1;

    auto check = [&] (int ans) {
        unordered_map<int, int> cnt;
        int mask = (1 << (ans + 1)) - 1;
        for (int j = 1; j <= n; j++) {
            int key = (a[j] & mask);
            cnt[key]++;
            if (cnt[key] >= k) {
                return true;
            }
        }

        return false;
    };

    int l = 0, r = 29, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (check(r)) {
        res = max(res, (LL)(k - 1) * (1 << (r + 1)));
    } else if (check(l)) {
        res = max(res, (LL)(k - 1) * (1 << (l + 1)));
    } 
    
    cout << res << "\n";
}
