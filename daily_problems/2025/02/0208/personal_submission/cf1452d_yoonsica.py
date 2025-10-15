import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1452/D

坐标线上有 $n + 2$ 个城镇，编号从 $0$ 到 $n + 1$ 。其中 $i$ 个城镇位于 $i$ 点。

您以概率 1/2 在每个城镇 建造一座无线电塔（这些事件是独立的）。之后，您希望将每个塔上的信号功率设置为从 $1$ 到 $n$ 之间的某个整数
（信号功率不一定相同，但也不一定不同）。位于城市 $i$ 的信号塔的信号功率为 $p$ ，其信号可到达每个城市 $c$ ，即 $|c - i| < p。

在建造信号塔后，您需要选择信号功率，以便：

- 城镇 $0$ 和 $n + 1$ 从无线电塔接收不到任何信号；
- 城镇 1, 2,...n 恰好各有一座无线电发射塔发出信号。

举例来说，如果 $n = 5$ 在 $2$ 、 $4$ 和 $5$ 建有无线电塔，则可以将 $2$ 镇的无线电塔的信号强度设置为 $2$ ，
将 $4$ 和 $5$ 镇的无线电塔的信号强度设置为 $1$ 。
这样， $0$ 和 $n + 1$ 镇就不会收到任何信号塔的信号，
$1$ 、 $2$ 和 $3$ 镇会收到 $2$ 镇信号塔的信号， $4$ 镇会收到 $4$ 镇信号塔的信号， $5$ 镇会收到 $5$ 镇信号塔的信号。

请计算在建造信号塔后，有办法设置信号功率以满足所有限制条件的概率。


思路：
考虑dp， 定义f[i]为成功覆盖前i个的概率
前i个点选一个点建塔j <= i,那么半径必定为j,这样才能覆盖到1，右边覆盖到j + j - 1, 要求j + j - 1 <= i
1 <= j <= (i + 1) / 2
选j建塔之后，还剩多少没被覆盖到？ n - (j + j - 1)
f[i] = sum(f[i - 2 * j + 1] * pow(1/2, j + j - 1) for j in range(1, (i + 1 // 2) + 1)
注意建塔与不建塔概率都是1/2，所以一个地方建塔与否都要乘1/2，所以答案可以转换成方案数除2^n
需要前缀和优化至O(n)，观察f[i] += f[i - 2 * j + 1]，由于j每次+1， i-2*j + 1会变化2，所以要分奇偶前缀和维护
'''
mod = 998244353
n = RI()
f = [0]*(n + 1)
f[0] = 1 # 第0个点不用覆盖

# n^2解法
# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         if i - 2 * j + 1 < 0:
#             break
#         f[i] += f[i - 2 * j + 1] * pow(p, j + j - 1, mod) % mod
#         f[i] %= mod

s = [0] * 2
s[0] = 1
for i in range(1, n + 1):
    # i >= i - 2 * j + 1 >= 0
    f[i] = s[(i & 1)^1] % mod
    s[i & 1] += f[i]
    s[i & 1] %= mod
p = pow(2, n, mod)
print(f[-1] * pow(p, -1, mod) % mod)