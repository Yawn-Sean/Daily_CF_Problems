**提示 1：** 相当于分为三段，每段的长度最大值尽可能短。

**提示 2：** 有多种方式处理。注意输出格式（虽然本题没有卡这个点）。

我们相当于要将一系列点分为三段，分别分配给三个站点，每个站点只需放在一段的中间即可。

于是我们只需使得三段的长度的最大值最小。

一种方式，可以直接使用二分，看长度为 $x$ 是否够用。顺序遍历即可，也可以处理分块更多的情况。

但排序后这题是可以 $\mathcal{O}(n)$ 完成的。只需前后安排两个指针，分别表示前面和后面的区间的两个端点，在前面一段较短时候移动前面的端点（否则浪费了前一段较短的优势），否则移动后面的端点，过程中一定经过答案。本质上是贪心和双指针。

最后，虽然这题没有卡输出，但实际上一个数除以 $2$ 的结果是可以无精度损失地输出的，因为我们可以根据这个数是奇数还是偶数，决定小数点后的是 `.500000` 还是 `.000000` ，前面的整数部分是显然可以无精度损失地求出来的。

时间复杂度为 $\mathcal{O}(n\log n)$ ，因为开头应该不得不排序。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LII()
    nums.sort()

    def div2(x):
        if x % 2: return f'{x // 2}.500000'
        return f'{x // 2}.000000'

    if n == 1 or n == 2:
        print(div2(0))
        print(div2(nums[0] * 2), div2(nums[-1] * 2), div2(0))
    else:
        l = 0
        r = n - 1
        
        cur = nums[r - 1] - nums[l + 1]
        idx = l + 1
        while l < r:
            if nums[l + 1] - nums[0] < nums[-1] - nums[r - 1]:
                l += 1
            else:
                r -= 1
            v = max(nums[l] - nums[0], nums[-1] - nums[r], nums[r - 1] - nums[l + 1])
            if v < cur: 
                cur = v
                idx = l + 1
        
        print(div2(cur))
        print(div2(nums[0] * 2 + cur), div2(nums[idx] * 2 + cur), div2(nums[-1] * 2 - cur))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    sort(nums.begin(), nums.end());

    auto div2 = [&] (int x) -> string {
        if (x & 1) return to_string(x / 2) + ".500000";
        return to_string(x / 2) + ".000000";
    };

    if (n < 3) {
        cout << div2(0) << '\n';
        cout << div2(nums[0] * 2) << ' ' << div2(nums.back() * 2) << ' ' << div2(0);
    }
    else {
        int l = 0, r = n - 1;
        int cur = nums[r - 1] - nums[l + 1], idx = l + 1;

        while (l < r) {
            if (nums[l + 1] - nums[0] < nums.back() - nums[r - 1]) l ++;
            else r --;
            int v = max(nums[l] - nums[0], max(nums.back() - nums[r], nums[r - 1] - nums[l + 1]));
            if (v < cur) cur = v, idx = l + 1;
        }

        cout << div2(cur) << '\n';
        cout << div2(nums[0] * 2 + cur) << ' ' << div2(nums[idx] * 2 + cur) << ' ' << div2(nums.back() * 2 - cur);
    }

    return 0;
}
```


