import collections
import sys
input = lambda: sys.stdin.readline().strip()

# 假设有质因子分解结果：n = x1 ^ c1 * x2 ^ c2 + x3 ^ c3
# 那么共有 (c1 + 1) * (c2 + 1) * (c3 + 1) 个数可以被 n 整除 （比如 x1 可以选择 0 ~ c1 个，共 c1 + 1 种选择）
# 因此可以通过分解质因子的方式得到 d(n) = (c1 + 1) * (c2 + 1) * (c3 + 1)
# 当执行一个查询时，n = n * x，即需要计算 d(n * x)，这可以通过分别做因子分解，再将分解结果合并来实现
# 接下来，需要找到一个质数 a，满足 n 和 a 互质，且 d(n * a) = n
# n 和 a 互质意味着他们各自的质因子分解结果中不存在相同的项，因此 d(n * a) = d(n) * d(a) = n
# 由于 d(n) * d(a) = n，则 d(n) 必须能够被 n 整除，即因子存在包含关系
# 题目要求判断这样的a是否存在，因此可以假设 a 为某个质数 z 的倍数来简化问题
# 即 a = z ^ c，则有 d(a) = c + 1 = n // d(n)，故有 c = n // d(n) - 1
# 此时，只要随意选择一个和 n 互质的质数 z，就可以保证 n 和 a 互质


def factor(v):
    cnter = collections.Counter()
    if v == 1:
        return cnter
    i = 2
    while i ** 2 <= v:
        while v % i == 0:
            v //= i
            cnter[i] += 1
        i += 1
    if v > 1:
        cnter[v] += 1
    return cnter


t = int(input())
ans = []
for _ in range(t):
    n, q = map(int, input().split())
    n_fac = factor(n)
    ori_n, ori_fac = n, collections.Counter(n_fac)
    for _ in range(q):
        line = list(map(int, input().split()))
        if line[0] == 2:
            n, n_fac = ori_n, collections.Counter(ori_fac)
            continue
        for v, c in factor(line[1]).items():
            n_fac[v] += c
        d = 1
        for c in n_fac.values():
            d *= c + 1
        d_fac = factor(d)
        ret = "YES"
        for v, c in d_fac.items():
            if c > n_fac[v]:
                ret = "NO"
                break
        ans.append(ret)

print("\n".join(ans))
