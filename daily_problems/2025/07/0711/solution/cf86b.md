**提示 1：** 有很多的构造方法，你可以尽情尝试。

因为可用的块很多，所以理解上，除了大小为 $1$ 的连通块，其他都能想办法覆盖。

证明这件事应该使用数学归纳法，把最边缘的一小块填上，然后保证剩余部分连通。这件事是很容易做到的，因此模拟这个过程，就可以解决问题了。

还有一些纯构造的方法。下面是这样的写法。

首先，如果我们遇到一个 `'.'` ，我们先看右侧 / 下侧有无填色。如果没有，我们直接染成同色。

否则，如果上侧 / 左侧 / 右侧染色了，那么就染成对应的颜色。

如果上述条件都不满足，只可能周围都是障碍物，输出 $-1$ 即可。

上述情况为何不会使得同色的大小超过 $5$ 呢？因为起步块大小是 $2$ ，接下来加入的块，右下角都是空的，因此只可能多出来 $3$ 个，因此符合题意。

还有超级多别的方法，欢迎写题解！

时间复杂度为 $\mathcal{O}(nm)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()
    grid = [[-1 if c == '#' else -2 for c in I()] for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] == -2:
                c = (i % 3) + (j % 3) * 3
                grid[i][j] = c
                if j + 1 < m and grid[i][j + 1] == -2:
                    grid[i][j + 1] = c
                elif i + 1 < n and grid[i + 1][j] == -2:
                    grid[i + 1][j] = c
                else:
                    if j and grid[i][j - 1] != -1: grid[i][j] = grid[i][j - 1]
                    elif i and grid[i - 1][j] != -1: grid[i][j] = grid[i - 1][j]
                    elif j + 1 < m and grid[i][j + 1] != -1: grid[i][j] = grid[i][j + 1]
                    else: exit(print(-1))

    print('\n'.join(''.join('#' if x == -1 else str(x) for x in y) for y in grid))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '.') {
                char c = '0' + (i % 3) + (j % 3) * 3;
                grid[i][j] = c;
                if (j + 1 < m && grid[i][j + 1] == '.') grid[i][j + 1] = c;
                else if (i + 1 < n && grid[i + 1][j] == '.') grid[i + 1][j] = c;
                else {
                    if (j && grid[i][j - 1] != '#') grid[i][j] = grid[i][j - 1];
                    else if (i && grid[i - 1][j] != '#') grid[i][j] = grid[i - 1][j];
                    else if (j + 1 < m && grid[i][j + 1] != '#') grid[i][j] = grid[i][j + 1];
                    else cout << -1, exit(0);
                }
            }
        }
    }

    for (auto &s: grid) cout << s << '\n';

    return 0;
}
```