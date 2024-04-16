"""
将字母a、b、c对应的顶点类型记作A、B、C。
所有顶点之间，只有A类和C类不能连边。
可以按照如下顺序连边：
1. B类顶点应与所有其他顶点连边，因此度为n-1的顶点即为B类顶点。
2. 其余顶点在删除与B类顶点的连边后，应构成不多于2个全联通分量，因此把度相同的顶点分为A类和C类。
3. 检查A类和C类顶点的顶点数是否满足度的约束。其中还包含一种特殊情况，即A类和C类的度相同、顶点数相同但被混为一类。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, m = lii()
    g = [[False] * n for _ in range(n)]
    for _ in range(m):
        i, j = lii()
        i -= 1; j -= 1
        g[i][j] = g[j][i] = True

    ans = [''] * n
    cntb = 0
    deg = [0] * n
    for i in range(n):
        s = sum(g[i])
        if s == n-1:
            ans[i] = 'b'
            cntb += 1
        else:
            deg[i] = s

    dega, degc = -1, -1
    cnta, cntc = 0, 0
    for i in range(n):
        if ans[i]:
            continue
        deg[i] -= cntb
        if deg[i] < 0:
            print('No')
            return
        if dega == -1 or deg[i] == dega:
            dega = deg[i]
            ans[i] = 'a'
            cnta += 1
        elif degc == -1 or deg[i] == degc:
            degc = deg[i]
            ans[i] = 'c'
            cntc += 1
        else:
            print('No')
            return

    if cntc == 0 and cnta == 2*(dega+1):
        for i in range(n):
            if ans[i] == 'b':
                continue
            ans[i] = 'c'
            for j in range(n):
                if g[i][j] and ans[j] != 'b':
                    ans[j] = 'c'
            break
        degc = dega
        cnta = cntc = cnta // 2

    if cnta == dega + 1 and cntc == degc + 1:
        print('Yes')
        print(*ans, sep='')
    else:
        print('No')

solve()