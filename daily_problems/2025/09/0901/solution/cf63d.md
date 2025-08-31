**提示 1：** 只要找到一条路径遍历方格内的每一个点，则截出来的任何连续的一段都是连通的，染色就行。

先看提示。

那么这条路径怎么构造呢？我们竖着走。

如果第一个长方形的 $a$ 是偶数，我们就从左上角出发，否则从左下角出发，然后都走完一列再往右侧走；这样，走到第二个长方形的时候，总是在左上角进入的。

接下来再用类似的方式遍历第二个长方形就行了。

最后将找到的路径依次分段染色为各个字符即可。

时间复杂度为 $\mathcal{O}((a+c)\max(b,d))$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    a, b, c, d, n = MII()
    nums = LII()

    N = fmax(b, d)
    M = a + c

    grid = [[-1] * M for _ in range(N)]

    for i in range(b):
        for j in range(a):
            grid[i][j] = -2

    for i in range(d):
        for j in range(c):
            grid[i][a + j] = -2

    if a % 2:
        x, y = b - 1, 0
        dx = -1
    else:
        x, y = 0, 0
        dx = 1

    pt = 0

    for i in range(a * b + c * d):
        if i:
            if 0 <= x + dx < N and grid[x + dx][y] == -2:
                x += dx
            else:
                y += 1
                dx = -dx
        
        while nums[pt] == 0:
            pt += 1
        nums[pt] -= 1
        
        grid[x][y] = pt

    print('YES')
    print('\n'.join(''.join('.' if x == -1 else chr(ord('a') + x) for x in line) for line in grid))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    int N = max(b, d), M = a + c;
    vector<string> grid(N, string(M, '.'));

    for (int i = 0; i < b; i ++) {
        for (int j = 0; j < a; j ++) {
            grid[i][j] = '?';
        }
    }

    for (int i = 0; i < d; i ++) {
        for (int j = 0; j < c; j ++) {
            grid[i][a + j] = '?';
        }
    }

    int x, y, dx;
    if (a & 1) x = b - 1, y = 0, dx = -1;
    else x = 0, y = 0, dx = 1;

    int pt = 0;

    for (int i = 0; i < a * b + c * d; i ++) {
        if (i) {
            if (x + dx >= 0 && x + dx < N && grid[x + dx][y] == '?') x += dx;
            else y ++, dx = -dx;
        }

        while (!nums[pt]) pt ++;
        nums[pt] --;
        
        grid[x][y] = 'a' + pt;
    }

    cout << "YES\n";
    for (auto &line: grid) cout << line << '\n';

    return 0;
}
```