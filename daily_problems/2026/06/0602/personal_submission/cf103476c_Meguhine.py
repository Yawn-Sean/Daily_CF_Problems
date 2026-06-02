import sys

n = int(input())

# 质因数分解
ps, cs = [], []
for x in range(2, 10**5):
    if x > n:
        break
    if n % x:
        continue
    ps.append(x)
    c = 0
    while True:
        n //= x
        c += 1
        if n % x:
            break
    cs.append(c)
if n != 1:
    ps.append(n)
    cs.append(1)

# 只有一个质因子, 特殊判断
m = len(ps)
if m == 1:
    print(f"2\n1 {ps[0]}")
    exit(0)

# 寻找出去和返回的维度
pu, cu, flag = 0, 0, False
for i, c in enumerate(cs):
    if c & 1:
        pu, cu = ps[i], c
        ps.pop(i)
        cs.pop(i)
        break
else:
    pu, cu, flag = ps[-1], cs[-1], True
    ps.pop()
    cs.pop()

# 寻找剩余维度的哈密顿路径
path = [1] * (cs[0] + 1)
for i in range(1, cs[0] + 1):
    path[i] = path[i - 1] * ps[0]
for p, c in zip(ps[1:], cs[1:]):
    nw = path.copy()
    mul = 1
    for i in range(c):
        mul *= p
        nw += (path if i & 1 else list(reversed(path)))
        for j in range(1, len(path) + 1):
            nw[-j] *= mul
    path = nw
path.pop(0)

# 构造答案
ans = []
if flag:
    ans = [pu] * cu
    for i in range(1, cu):
        ans[i] = ans[i - 1] * pu
else:
    ans = [1] * (cu + 1)
    for i in range(1, cu + 1):
        ans[i] = ans[i - 1] * pu
mul = ans[-1]
for layer in range(cu - 1):
    ans += (list(reversed(path)) if layer & 1 else path)
    for i in range(1, len(path) + 1):
        ans[-i] *= mul
    mul //= pu

# 最后两层单独处理
if flag:
    mul2 = mul // pu
    for i, x in enumerate(reversed(path)):
        ans += [x * mul2, x * mul] if i & 1 else [x * mul, x * mul2]
else:
    for layer in range(cu - 1, cu + 1):
        ans += (list(reversed(path)) if layer & 1 else path)
        for i in range(1, len(path) + 1):
            ans[-i] *= mul
        mul //= pu

# 输出
print(len(ans))
print(' '.join(map(str, ans)))


"""
把 1 看成原点, 一共有 len(ps) 个维度
第 i 个维度从 0 到 cs[i]
这样形成了一个高维长方体

假如有一维的 (cs[i]+1) 是偶数, 那我们把这一维单独拎出来, 用作出去和返回的维度.
先从 1 一路走到 pow(ps[i],cs[i])
然后任选另外一个维度 j, 走到 pow(ps[i],cs[i])*ps[j]
接下来对于去掉 i 的维度, 我们找一条从 ps[j] 开始的汉密尔顿**路径** (不是回路)
- 这一定可以做到, 考虑递归寻找
    - 先在去掉一个维度的图上找一条路径
    - 然后在新的维度上来回颠倒这条路径即可
我们把这条路径的起点和终点记为 S, T
我们每次在 S <-> T 之间正着或者倒着走一遍, 然后 // ps[i]
最后一定能返回到 1

那如果全部的 (cs[i]+1) 都是奇数怎么办呢? 我们不妨把 1 去掉.
还是任选一个维度 i, 先从 ps[i] 走到 pow(ps[i],cs[i])
然后仿照偶数的过程, 一路回到 ps[i] 的 T 的位置
接下来在回到 ps[i] 的 S 的过程当中, 每次 // ps[i] 和 * ps[i], 最后回到 ps[i]
因为全部的 (cs[i]+1) 都是奇数, 当删去了一个点之后, 剩余的一定是偶数, 因此这种构造可行
"""
