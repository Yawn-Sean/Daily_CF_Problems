"""
数据输入很简单，范围很大，可能有公式解法，可能可以贪心
能不能每个 u 都贪心找 (u + k) % n ?
不可以，比如 n = 6, k = 2, 这个时候会成环, 需要错开一个位置
什么情况下会成环?
n % k == 0 时，从 0 号点出发连长度为 k 的边, 会最终连到 n
每转一圈, 就得有一个只能走 k - 1 的, 才能把环错开
n % k != 0 呢? 但是 gcd(n, k) != 0, 比如 n = 9, k = 6
这样也是会成环的，先走 lcm(n, k) / k - 1 个 k 长度, 然后就得走一个 k - 1 长度去修正一下
当 lcm(n, k) = n * k 时，其实就可以 k 步走 n - 1 轮, 直接变成一棵树了
综上, 求 lcm(n, k) / k, 每 lcm(n, k) / k 次操作为一组, 每组的总权值为 k * (lcm(n, k) / k - 1) + k - 1
一共需要 n - 1 次操作
"""

import sys

input = lambda: sys.stdin.readline().strip()

from math import lcm

n, k = map(int, input().split())
period = lcm(n, k) // k
cnt = k * (period - 1) + k - 1

res = (n - 1) // period * cnt
left = (n - 1) % period
res += left * k
print(res)
