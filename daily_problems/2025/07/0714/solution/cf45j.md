**提示 1：** 简单构造。

**提示 2：** 小的图形可能构造不了，记得确认下。

可以先将矩形黑白间隔染色，黑色填上小的数，白色填上大的数，同时让两组之间填数大小关系尽可能对应，即让小的黑数周围刚好也是小的白数，就可以构造了。

对于足够大的 $n,m$ ，差距已经够大。对于 $n,m$ 较小的情况，可以暴力跑下，确认是否有解，并给出对应的构造。

时间复杂度为 $\mathcal{O}(nm)$ 。


### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()

    if 2 < n + m < 5: print(-1)
    else:
        grid = [[0] * m for _ in range(n)]
        
        pt = 1
        for i in range(n):
            for j in range(m):
                if (i + j) % 2:
                    grid[i][j] = pt
                    pt += 1
        
        for i in range(n):
            for j in range(m):
                if (i + j) % 2 == 0:
                    grid[i][j] = pt
                    pt += 1
        
        print('\n'.join(' '.join(map(str, x)) for x in grid))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n + m > 2 && n + m < 5) cout << -1;
    else {
        vector<vector<int>> grid(n, vector<int>(m));
        int pt = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2) {
                    grid[i][j] = ++pt;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2 == 0) {
                    grid[i][j] = ++pt;
                }
            }
        }

        for (auto &x: grid) {
            for (auto &y: x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
```