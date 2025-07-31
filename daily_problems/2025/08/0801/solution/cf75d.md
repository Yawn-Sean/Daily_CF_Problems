**提示 1：** 子段和可能有两种情况：跨段落 / 在一个段落内。分别如何处理？

先看提示。对于在段落内的，我们可以对每一个序列分别求最大子段和，最后，取在最后序列中出现的最大值。

而如果跨段落了，考虑最后一个取了数的段落，则这个段落必然取最大前缀，这个是可以预处理的。而前面的部分取的是最大的后缀，这个东西也是可以通过维护每一段的最大后缀和段和完成实现的。

到某个位置的最大后缀=max(前一段的最大后缀+这一段的和，这一段的最大后缀)

注意这里序列非空，所以一些细节还是得看。

时间复杂度为 $\mathcal{O}(\sum k+m)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()
    
    pref = []
    suff = []
    res = []
    total = []
    
    for _ in range(n):
        k, *nums = LII()
        
        cur = 0
        p = -10000
        
        for i in range(k):
            cur += nums[i]
            p = fmax(p, cur)
        
        pref.append(p)
        total.append(cur)
        
        cur = 0
        s = -10000
        
        for i in range(k - 1, -1, -1):
            cur += nums[i]
            s = fmax(s, cur)
        
        suff.append(s)
    
        cur = 0
        r = -10000
        
        for i in range(k):
            cur = fmax(cur, 0) + nums[i]
            r = fmax(cur, r)
        
        res.append(r)
    
    idxs = LGMI()
    
    ans = -10000
    
    cur = 0
    for idx in idxs:
        ans = fmax(ans, res[idx])
        ans = fmax(ans, cur + pref[idx])
        cur = fmax(cur + total[idx], suff[idx])
    
    print(ans)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int inf = 1e5;
    vector<int> pref(n, -inf), suff(n, -inf), total(n, 0), res(n, -inf);

    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;

        vector<int> nums(k);
        for (auto &v: nums)
            cin >> v;

        for (auto &v: nums) {
            total[i] += v;
            pref[i] = max(pref[i], total[i]);
        }

        int cur;

        cur = 0;
        for (auto &v: nums) {
            cur = max(cur, 0) + v;
            res[i] = max(res[i], cur);
        }

        reverse(nums.begin(), nums.end());
        cur = 0;
        for (auto &v: nums) {
            cur += v;
            suff[i] = max(suff[i], cur);
        }
    }

    long long cur = 0, ans = -inf;
    while (m --) {
        int idx;
        cin >> idx;
        idx --;

        ans = max(ans, (long long)res[idx]);
        ans = max(ans, cur + pref[idx]);
        cur = max(cur + total[idx], (long long)suff[idx]);
    }
    cout << ans;

    return 0;
}
```