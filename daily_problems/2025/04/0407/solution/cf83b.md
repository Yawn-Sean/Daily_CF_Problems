**提示 1：** 一轮一轮地考虑问题，第 $k$ 轮后看了多少人？

**提示 2：** 如何确定开始跑了多少轮？

我们称一个队伍全部被操作一遍为一轮，假设经过了 $k$ 轮，则每个元素的检查次数等于 $\min(a_i,k)$ 。

于是，可以直接得到经过 $k$ 轮的总检查人数。

我们的目标是找到总共检查 $v$ 个人时的队列情况。于是我们应该让前面 $k$ 轮后，剩下的操作次数比较小。那么我们不妨求出最大的轮数 $k$ ，那么剩下的操作次数就不超过队伍长度了。

这个 $k$ 显然可以二分得到。

接下来剩下的人直接模拟即可。

时间复杂度为 $\mathcal{O}(n\log M)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, k = MII()
    nums = LII()

    if sum(nums) < k:
        print(-1)
    else:
        l, r = 0, 10 ** 9
        while l <= r:
            m = (l + r) // 2
            v = 0
            for x in nums:
                v += fmin(x, m)
            if v <= k:
                l = m + 1
            else:
                r = m - 1
        
        tmp = []
        for i in range(n):
            if nums[i] > r:
                tmp.append(i)
            k -= fmin(nums[i], r)
            nums[i] -= fmin(nums[i], r)
        
        for i in range(k):
            nums[tmp[i]] -= 1
        
        ans = []
        for i in range(k, len(tmp)):
            if nums[tmp[i]]:
                ans.append(tmp[i] + 1)
        
        for i in range(k):
            if nums[tmp[i]]:
                ans.append(tmp[i] + 1)
        
        print(' '.join(map(str, ans)))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> nums(n);
    long long total = 0;

    for (auto &x: nums)
        cin >> x, total += x;

    if (total < k) cout << -1;
    else {
        int l = 0, r = 1e9;
        while (l <= r) {
            int m = (l + r) / 2;
            long long v = 0;
            for (auto &x: nums)
                v += min(x, m);
            if (v <= k) l = m + 1;
            else r = m - 1;
        }

        vector<int> tmp;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > r) tmp.emplace_back(i);
            k -= min(nums[i], r);
            nums[i] -= min(nums[i], r);
        }

        for (int i = 0; i < k; i ++)
            nums[tmp[i]] --;
        
        for (int i = k; i < tmp.size(); i ++)
            if (nums[tmp[i]]) cout << tmp[i] + 1 << ' ';
        
        for (int i = 0; i < k; i ++)
            if (nums[tmp[i]]) cout << tmp[i] + 1 << ' ';
    }

    return 0;
}
```