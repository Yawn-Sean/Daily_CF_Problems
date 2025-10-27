"""
考虑最小的 cnt，使得 cnt * (cnt - 1) // 2 >= k
如果恰好等于，则只需要让前 cnt 个元素一样就好了
如果不是恰好等于，则考虑前 cnt - 1 个元素两两之间整除
第 cnt 个元素和前面的 k - (cnt - 1) * (cnt - 2) // 2 个元素有关系
设 x = k - (cnt - 1) * (cnt - 2) // 2
则不妨前 cnt 个数中，选 x 个 2，cnt - 1 - x 个 4，1 个 6
后边的数和前面的 cnt 个数不能有整除关系，其内部也不能有
最稳妥的方法是选素数，但是素数个数不够凑 1e5 个
我有一个想法，5e5 + 1 到 1e6 之间，这些数肯定不会能整除的对
我们只要再保证，这里面的数不会被 2 或 4 或 6 整除就好了
其实本质上就是不会被 2 和 3 整除，我们考虑拿模 6 余 1 和 5 的数就好了
这样相当于每 6 个数里面拿 2 个数，5e5 / 3 也是超过 1e5 的，能选够
"""

import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
k = int(input())
if k > n * (n - 1) // 2:
    print("-1")
else:
    cnt = 0
    for i in range(1, n + 1):
        if i * (i - 1) // 2 >= k:
            cnt = i
            break

    res = []
    if cnt * (cnt - 1) // 2 == k:
        for i in range(cnt):
            res.append(2)
    else:
        x = k - (cnt - 1) * (cnt - 2) // 2
        for i in range(x):
            res.append(2)
        for i in range(cnt - 1 - x):
            res.append(4)
        res.append(6)

    st = int(5e5 + 10)
    ed = int(1e6)
    for i in range(st, ed, 1):
        if len(res) == n:
            break
        if i % 6 == 1 or i % 6 == 5:
            res.append(i)
    print(*res)
