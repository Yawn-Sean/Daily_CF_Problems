**提示 1：** 可以尽量使我们后面构造的部分不影响前面构造的部分。

**提示 2：** 从大数往小数考虑就行。

提示 1 是我们的主要想法，就是一个一个数放进最终的答案序列。

怎么才能让后面插入的数字不影响前面的数字呢？

发现条件中我们只需要考虑比当前数字更大的数。所以如果插入的数字越来越小，那么后面的数就不会对前面的数造成影响。

因此我们考虑将 $n,n-1,\dots,1$ 依次插入序列。每次只需满足插入的位置前面恰好有 $nums[i]$ 个数不比 $i+k$ 小就行。因为保证能构造，所以不比 $i+k$ 小的数一定足够多。同时你可以在任何一个位置插入，所以对于任何一个可能的数量都能找到合适的位置。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, k = MII()
    nums = LII()

    ans = []

    for i in range(n - 1, -1, -1):
        nans = []
        
        c = 0
        for x in ans:
            if c == nums[i]:
                nans.append(i)
                c += 1
            nans.append(x)
            if x >= i + k:
                c += 1
        
        if c == nums[i]:
            nans.append(i)
        
        ans = nans

    print(*(x + 1 for x in ans))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> nums[i];
    
    vector<int> ans;
    for (int i = n; i > 0; i --) {
        vector<int> nans;

        int c = 0;
        for (auto &x: ans) {
            if (c == nums[i]) {
                nans.emplace_back(i);
                c ++;
            }
            nans.emplace_back(x);
            c += (x >= i + k);
        }

        if (c == nums[i]) nans.emplace_back(i);
        swap(ans, nans);
    }

    for (auto &v: ans) cout << v << ' ';

    return 0;
}
```