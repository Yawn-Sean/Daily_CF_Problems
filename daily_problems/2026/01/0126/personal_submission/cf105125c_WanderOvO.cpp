/*
字典序需要贪心
对于 s[k]，我们首先要看 s[k] 的第一个字符最小是多少
我们对 a 进行排序，则 s[k] 的第一个字符最小是 a[k]
第二个字符呢？
对于前面的字符串，他们的字典序仍然要不大于 s[k] 的
如果字符串已经严格小于 s[k] 了，那么就可以拿后边大的字符拼
我们其实只关心还没和 s[k] 分出大小的那些，这个似乎可以用二分求出来
假设加上 s[k] 本身，前 k 个里面共有 cnt 个和 s[k] 并列大的
则这 cnt 个取目前最小的 cnt 个字符，再看一下是否决出了胜负，一直这样做下去
*/

void solve() {
    int n, m;
    cin >> n >> m;
    int limit = n * m;
    vector<int> cnt(limit + 1, 0);
    for (int i = 0; i < limit; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> vals;
    vals.reserve(limit);
    for (int i = 1; i <= limit; i++) {
        int num = cnt[i];
        cnt[i] += cnt[i - 1];
        while (num--) {
            vals.push_back(i);
        }
    }

    for (int k = 1; k <= n; k++) {
        int start = -1; 
        int cur = k;  

        for (int j = 0; j < m; j++) {
            start += cur;
            int val = vals[start];
            
            cout << val << (j == m - 1 ? "" : " ");
            cur = min(cur, start - cnt[val - 1] + 1);
        }
        cout << '\n';
    }
}
