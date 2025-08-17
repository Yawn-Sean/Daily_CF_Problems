**提示 1：** 把一段增后减的段落称为一个山，每个山的最优结果怎么确定？

**提示 2：** 上述做法能推广到整个数组吗？

如果这个数组就是先递增（可能有些相等），再递减的（也可能有些相等），怎么做呢？

直接在两侧赋值为 $1$ ，再往中间走一次就行，每次需要增大的时候都加上 $1$ 。

而一个数组恰好是由一堆这样的情况组成的，所以，只需顺着遍历一遍再反着遍历一遍就行了。

时间复杂度为 $\mathcal{O}(n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    s = I()
    
    ans = [1] * n
    
    for i in range(n - 1):
        if s[i] == 'R': ans[i + 1] = ans[i] + 1
        elif s[i] == '=': ans[i + 1] = ans[i]
    
    for i in range(n - 2, -1, -1):
        if s[i] == 'L': ans[i] = fmax(ans[i], ans[i + 1] + 1)
        elif s[i] == '=': ans[i] = ans[i + 1]
    
    print(*ans)
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

    vector<int> ans(n, 1);

    for (int i = 0; i < n - 1; i ++) {
        if (s[i] == 'R') ans[i + 1] = ans[i] + 1;
        else if (s[i] == '=') ans[i + 1] = ans[i];
    }

    for (int i = n - 2; i >= 0; i --) {
        if (s[i] == 'L') ans[i] = max(ans[i], ans[i + 1] + 1);
        else if (s[i] == '=') ans[i] = ans[i + 1];
    }
    
    for (auto &x: ans) cout << x << ' ';

    return 0;
}
```