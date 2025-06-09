**提示 1：** 先不满足对称条件可以如何构造。

（下面的思路有点强行解释的意思，感觉还是主要靠观察）

如果不需要满足主对角线为 $0$ 的条件，则直接取 $a_{i,j}=(i+j)\bmod n$ 就行了。

但是目前要求。这也提示我们最后一列与最后一行是完全一致的。这样，如果我们将最后一列 / 最后一行的数字填入到对应列 / 对应行的主对角线上，则 $(n-1)\times(n-1)$ 的矩阵也满足类似性质——对称且同行同列不出现同数（除了主对角线非 $0$ 之外）。

因此我们先找到一个 $(n-1)\times(n-1)$ 的对称矩阵，使得整体对称，再将主对角线的元素移动到最后一行和最后一列就行。

发现我们最开始构造的矩阵就是对称矩阵，因此已经完成了任务。

$n$ 等于偶数，即 $n-1$ 为奇数，恰好保证了主对角线的元素两两不同。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()

    ans = [[0] * n for _ in range(n)]

    for i in range(n - 1):
        for j in range(n - 1):
            ans[i][j] = (i + j) % (n - 1) + 1

    for i in range(n):
        ans[-1][i] = ans[i][i]
        ans[i][-1] = ans[i][i]
        ans[i][i] = 0

    print('\n'.join(' '.join(map(str, x)) for x in ans))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            grid[i][j] = (i + j) % (n - 1) + 1;
        }
    }

    for (int i = 0; i < n; i ++) {
        grid[n - 1][i] = grid[i][i];
        grid[i][n - 1] = grid[i][i];
        grid[i][i] = 0;
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
```