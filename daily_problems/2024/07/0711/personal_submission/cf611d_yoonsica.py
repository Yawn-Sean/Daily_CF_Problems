import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
# ---------------------------------------分割线---------------------------------------------------------
n = RI()
s = RS()
mod = 10 ** 9 + 7

f = [0] * (n + 1)  # f[i][j] 最后一个以i结束，j开始的方案
s = '0' + s
ans = 0

# 预处理最长公共前缀，用来比较两个字符串大小
prefix = [[0] * (n + 2) for _ in range(n + 2)]

for i in range(n, 0, -1):
    for j in range(n, 0, -1):
        if s[i] == s[j]:
            prefix[i][j] = prefix[i + 1][j + 1] + 1


def is_valid(a, b):
    # 比较s[a:b] 和 s[b:c] 小于返回true
    t = prefix[a][b]
    if t >= b - a:
        return False
    return s[a + t] < s[b + t]


# f[k][i - 1]
pre = [[0] * (n + 1) for _ in range(n + 1)]  # 维护以i结束的长度小于等于j的方案数
f[1] = 1
for i in range(1, n + 1):
    g = [0] * (n + 1)
    g[1] = 1
    for j in range(1, i + 1):
        if s[j] == '0':
            continue
        # i - j + 1 > j - k
        k = max(1, 2 * j - i)
        # 先计算长度小于j - i + 1的部分，这部分肯定都满足要求
        # 以i - 1结尾，长度小于j - i + 1
        g[j] = (g[j] + pre[j - 1][j - 1] - pre[j - 1][k - 1]) % mod
        # 然后计算长度相同的部分，比较字符串大小
        k -= 1
        # i - k < j - i + 1
        if k >= 0 and is_valid(k, j):
            g[j] = (g[j] + pre[j - 1][k] - pre[j - 1][k - 1]) % mod
    for j in range(1, i + 1):
        pre[i][j] = (pre[i][j - 1] + g[j]) % mod
    f = g
print(sum(f) % mod)
