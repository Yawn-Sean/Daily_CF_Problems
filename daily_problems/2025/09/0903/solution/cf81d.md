**提示 1：** 先选出来数再排列。

总长度是 $n$ 的话，每个元素最多选多少个呢？最多选 $\lfloor n/2\rfloor$ 个，因为隔一个放一个也只能放那么多。

因此我们按照这个界提取元素，直到拿到 $n$ 个元素，接下来再排列它们。如果取不出来这么多，就无法构造。

取出来后有多种构造方案，一种是这样：

列出两个序列 $1,3,5,\dots$ ， $2,4,6,\dots$ ，先填入第一组，再填入第二组。

容易产生矛盾的是出现频率较高的数字，且只有刚好是 $n/2$ 的情况下会在上面的构造中产生矛盾（可能出现填入 $3,5,\dots$ 位置和 $2$ 位置的情况）。于是直接先处理 $n/2$ 频率的元素避免上面的矛盾，再填入其他元素。

时间复杂度为 $\mathcal{O}(n+m)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()
    nums = LII()
    
    for i in range(m):
        nums[i] = fmin(nums[i], n // 2)
    
    total = []
    
    for i in sorted(range(m), key=lambda x: -nums[x]):
        while len(total) < n and nums[i]:
            total.append(i + 1)
            nums[i] -= 1
    
    if len(total) < n:
        exit(print(-1))
    
    ans = [0] * n
    
    pt = 0
    for x in total:
        ans[pt] = x
        pt += 2
        
        if pt >= n:
            pt = 1
    
    print(*ans)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(m);
    for (auto &x: nums) cin >> x;

    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] > nums[j];});

    vector<int> to_assign;
    for (auto &x: order) {
        int v = min(nums[x], n / 2);
        while ((v --) && to_assign.size() < n) {
            to_assign.emplace_back(x + 1);
        }
    }

    if (to_assign.size() < n) return cout << -1, 0;

    vector<int> ans(n);
    int pt = 0;

    for (auto &x: to_assign) {
        ans[pt] = x;
        pt += 2;
        if (pt >= n) pt = 1;
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}
```