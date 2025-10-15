**提示 1：** 每个位置对应一个序列，只需看哪个序列出现次数最多即可。

对于每个元素，使得 $i$ 位置数值为 $a_i$ 的序列最多只有一个，我们可以借此推出整个数组的第一个元素，再看哪个 “第一个元素” 出现的最多，就意味着如果把这个数字作为第一个元素的数组这些位置无需修改，也就是修改的次数最少。

最后，注意修改后的第一个元素需要是正整数，所以 $0$ 和负整数不加入统计。

时间复杂度为 $\mathcal{O}(n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LII()

    cnt = [0] * (10 ** 5 + 1)

    for i in range(n):
        x = nums[i] - fmin(i, n - 1 - i)
        if x > 0:
            cnt[x] += 1

    print(n - max(cnt))
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
    for (auto &v: nums) cin >> v;

    vector<int> cnt(100005, 0);
    for (int i = 0; i < n; i ++) {
        int x = nums[i] - min(i, n - 1 - i);
        if (x > 0) cnt[x] ++;
    }

    cout << n - *max_element(cnt.begin(), cnt.end());

    return 0;
}
```
