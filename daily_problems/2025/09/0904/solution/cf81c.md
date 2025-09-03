**提示 1：** 每个元素对最终结果的贡献如何？

第一组元素共有 $a$ 个，每个元素对均值的贡献是 $\frac{1}{a}$ 。第二部分的贡献是 $\frac{1}{b}$ 。

我们要总贡献最大，就应该把让大数的贡献更大，小数的贡献更小。

所以在 $a$ 更大时，应当把最小的元素分给第一组；在 $a$ 更小时，应当把最大的元素分给第一组。而如果数量一样，怎么分配都不影响最终答案。

注意，我们要求给出标号序列字典序最小的解。

所以选择最小的元素和最大元素时，如果数值一样，应当下标越小的越标成第一组，可以使用双关键字，也可以用下标序列进行稳定排序；而数量一样的情况直接把前一半标记成 $1$ 后一半标记成 $2$ 就是字典序最小的答案了。

时间复杂度为 $\mathcal{O}(n)$ ，因为值域较小，可以使用基数排序等。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    a, b = MII()
    nums = LII()
    
    if a == b:
        print(*([1] * a + [2] * b))
    else:
        ans = [2] * n
        
        to_choose = list(range(n))
        if a > b:
            to_choose.sort(key=lambda x: nums[x])
        else:
            to_choose.sort(key=lambda x: -nums[x])
        
        for i in range(a):
            ans[to_choose[i]] = 1
        
        print(*ans)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    if (a == b) {
        while (a --) cout << "1 ";
        while (b --) cout << "2 ";
    }
    else {
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);

        if (a < b) stable_sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return nums[i] > nums[j];});
        else stable_sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return nums[i] < nums[j];});

        vector<int> ans(n, 2);
        for (int i = 0; i < a; i ++) ans[idxs[i]] = 1;

        for (auto &v: ans) cout << v << ' ';
    }

    return 0;
}
```