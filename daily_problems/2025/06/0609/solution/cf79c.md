**提示 1：** 固定右端点，能取的最左的左端点满足什么条件呢？

**提示 2：** 维护上面的东西就行。

考虑提示 1。

左端点要么是 $0$ ，要么是上次出现无聊字符串的位置 $+1$ 。所以可以在顺序遍历的过程中，暴力对比字符串找上一次出现的位置，最后与当前最优结果取最大值即可。

时间复杂度为 $\mathcal{O}(n|s|^2)$ ，是非常朴素的实现。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    s = I()
    n = II()
    strs = [I() for _ in range(n)]

    start, length = 0, 0
    mi_start = 0

    for i in range(len(s)):
        for w in strs:
            if i + 1 >= len(w) and s[i + 1 - len(w):i + 1] == w:
                mi_start = fmax(mi_start, i + 1 - len(w) + 1)
        if i + 1 - mi_start > length:
            start = mi_start
            length = i + 1 - mi_start

    print(length, start)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> strs(n);
    for (auto &x: strs) cin >> x;

    int start = 0, length = 0, mi_start = 0;

    for (int i = 0; i < s.size(); i ++) {
        for (auto &x: strs) {
            if (i + 1 >= x.size() && s.substr(i + 1 - x.size(), x.size()) == x) {
                mi_start = max(mi_start, i + 1 - (int)x.size() + 1);
            }
        }
        if (i - mi_start + 1 > length) {
            start = mi_start;
            length = i - mi_start + 1;
        }
    }

    cout << length << ' ' << start;

    return 0;
}
```