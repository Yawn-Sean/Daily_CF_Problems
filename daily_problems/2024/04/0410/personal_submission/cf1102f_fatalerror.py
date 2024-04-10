import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

# 需要大量使用min/max的dp题，手写min/max更快
min_ = lambda a, b: a if a < b else b
max_ = lambda a, b: a if a > b else b

inf = 1 << 31

def solve():
    m, n = lii()
    mat = [lii() for _ in range(m)]
    if m == 1:
        return min(abs(mat[0][j]-mat[0][j+1]) for j in range(n-1))

    # 预处理两个数组相邻时、分别作为头尾时的最小相邻元素差值
    adjdiff = [[0] * m for _ in range(m)]
    beginenddiff = [[0] * m for _ in range(m)]
    for i, row1 in enumerate(mat):
        for j, row2 in enumerate(mat):
            adjdiff[i][j] = min(abs(x-y) for x, y in zip(row1, row2))
            beginenddiff[i][j] = min((abs(x-y) for x, y in zip(row1[1:], row2[:-1])), default=inf)

    # 预处理各个bitcount下的mask
    mx = 2**m
    bitcnt = [0] * mx
    for i in range(m):
        hb = 1 << i
        for j in range(hb):
            bitcnt[hb | j] = bitcnt[j] + 1
    cntmasks = [[] for _ in range(m+1)]
    for ma, c in enumerate(bitcnt):
        cntmasks[c].append(ma)

    def calc(start):
        dp = [[0] * mx for _ in range(m)]
        dp[start][1<<start] = inf
        for c in range(2, m+1):
            for cur in cntmasks[c]:
                if not cur & (1 << start):
                    continue
                # 可以逐位枚举
                # for i in range(m):
                #     if i == start or not cur & (1 << i):
                #         continue
                #     pre = cur ^ (1 << i)
                #     for j in range(m):
                #         if not pre & (1 << j):
                #             continue
                #         dp[i][cur] = max_(dp[i][cur], min_(dp[j][pre], adjdiff[j][i]))
                # 也可以按lowbit枚举
                tmpcur = cur ^ (1 << start)
                while tmpcur:
                    lbcur = tmpcur & -tmpcur
                    i = lbcur.bit_length()-1
                    pre = cur ^ lbcur
                    tmppre = pre
                    while tmppre:
                        lbpre = tmppre & -tmppre
                        j = lbpre.bit_length()-1
                        dp[i][cur] = max_(dp[i][cur], min_(dp[j][pre], adjdiff[j][i]))
                        tmppre -= lbpre
                    tmpcur -= lbcur
        return max(min_(dp[i][mx-1], beginenddiff[start][i]) for i in range(m) if i != start)

    return max(calc(i) for i in range(m))

print(solve())
