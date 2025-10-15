**提示 1：** 最后只有两种形态。

**提示 2：** 操作能完成什么事儿？

最后形态是相邻两两不同，于是只可能是 $010\dots$ 或者 $101\dots$ 。

枚举目标串的具体形态。而每次操作最多把一个位置改成目标元素（因为修改前是相同的，一定至少一个跟目标串对上），而在没有达成目标的情况下，一定能找到相邻的相等元素（除非一开始字符串是另一个）。

所以操作次数刚好是不匹配的位置个数。于是统计这个就行。

注意只需统计一次，因为两个个数之和等于 $n$ 。

时间复杂度为 $\mathcal{O}(n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    s = I()

    v = 0
    for i in range(n):
        v += int(s[i]) != i % 2

    print(fmin(v, n - v))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int v = 0;
    for (int i = 0; i < n; i ++)
        v += ((s[i] & 1) == (i & 1));
    
    cout << min(v, n - v);

    return 0;
}
```