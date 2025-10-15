**提示 1：** 自己在草稿纸上多尝试，很容易发现有些情况的构造。

**提示 2：** 其他情况可以构造吗？

自己手动尝试，容易发现 $n$ 或 $m$ 为偶数时是很好构造的。

我们以 $n$ 为偶数为例。我们可以先从 $(1,1)$ 走到 $(n,1)$ ，再蛇形走位走到起点。

接下来看上面的构造没有覆盖的特殊情况。

首先是 $n,m$ 都是奇数。此时，考虑总共走的步数 $nm$ 是奇数。如果我们不设传送门，则每走一步，所在位置的横纵坐标之和的奇偶性都发生改变。因此走 $nm$ 步后横纵坐标之和奇偶性发生改变，与回到起点矛盾。

因此必须设传送门。然后只需从 $(1,1)$ 蛇形走位到 $(n,m)$ 再传送即可。

剩余的情况是 $n,m$ 中有 $1$ ，此时影响到了上述构造中 “先走过去，再走回来” 的逻辑。此时，如果 $nm=2$ ，我们只需来回走一步即可；否则，不得不在底端设置一个传送门，因为之前的每一步走法都是固定的。

时间复杂度为 $\mathcal{O}(nm)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()

    if n == 1:
        if m == 2:
            print(0)
            print(1, 1)
            print(1, 2)
            print(1, 1)
        else:
            print(1)
            print(1, m, 1, 1)
            print('\n'.join(f'1 {i}' for i in range(1, m + 1)))
            print(1, 1)

    elif m == 1:
        if n == 2:
            print(0)
            print(1, 1)
            print(2, 1)
            print(1, 1)
        else:
            print(1)
            print(n, 1, 1, 1)
            print('\n'.join(f'{i} 1' for i in range(1, n + 1)))
            print(1, 1)

    elif n % 2 == 0:
        print(0)
        outs = []
        outs.append('\n'.join(f'{i} 1' for i in range(1, n + 1)))
        
        for i in range(n):
            if i % 2 == 0: outs.append('\n'.join(f'{n - i} {j}' for j in range(2, m + 1)))
            else: outs.append('\n'.join(f'{n - i} {j}' for j in range(m, 1, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))

    elif m % 2 == 0:
        print(0)
        outs = []
        outs.append('\n'.join(f'1 {i}' for i in range(1, m + 1)))
        
        for i in range(m):
            if i % 2 == 0: outs.append('\n'.join(f'{j} {m - i}' for j in range(2, n + 1)))
            else: outs.append('\n'.join(f'{j} {m - i}' for j in range(n, 1, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))

    else:
        print(1)
        print(n, m, 1, 1)
        
        outs = []
        for i in range(1, n + 1):
            if i % 2: outs.append('\n'.join(f'{i} {j}' for j in range(1, m + 1)))
            else: outs.append('\n'.join(f'{i} {j}' for j in range(m, 0, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))
```

C++ 做法如下——

```cpp []

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m == 2) cout << "0\n1 1\n1 2\n1 1";
        else {
            cout << 1 << '\n';
            cout << 1 << ' ' << m << " 1 1\n";
            for (int i = 1; i <= m; i ++)
                cout << 1 << ' ' << i << '\n';
            cout << "1 1";
        }
    }
    else if (m == 1) {
        if (n == 2) cout << "0\n1 1\n2 1\n1 1";
        else {
            cout << 1 << '\n';
            cout << n << " 1 1 1\n";
            for (int i = 1; i <= n; i ++)
                cout << i << ' ' << 1 << '\n';
            cout << "1 1";
        }
    }
    else if ((n & 1) == 0) {
        cout << "0\n";

        for (int i = 1; i <= n; i ++)
            cout << i << ' ' << 1 << '\n';
        
        for (int i = n; i >= 1; i --) {
            int v = (i & 1 ? m : 2), dv = (i & 1 ? -1 : 1);
            for (int j = 0; j < m - 1; j ++) {
                cout << i << ' ' << v << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }
    else if ((m & 1) == 0) {
        cout << "0\n";
        for (int i = 1; i <= m; i ++)
            cout << 1 << ' ' << i << '\n';
        
        for (int i = m; i >= 1; i --) {
            int v = (i & 1 ? n : 2), dv = (i & 1 ? -1 : 1);
            for (int j = 0; j < n - 1; j ++) {
                cout << v << ' ' << i << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }
    else {
        cout << "1\n";
        cout << n << ' ' << m << " 1 1\n";
        for (int i = 1; i <= n; i ++) {
            int v = (i & 1 ? 1 : m), dv = (i & 1 ? 1 : -1);
            for (int j = 0; j < m; j ++) {
                cout << i << ' ' << v << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }

    return 0;
}
```