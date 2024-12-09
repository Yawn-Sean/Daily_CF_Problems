'''
https://codeforces.com/problemset/submission/533/292574497
533B
20241121 Y2
2000
Tree DP
'''
# dp[i]表示以i为根节点的子树的最大值，有以下分类讨论：
# dp[i][1]: 表示子树节点个数为奇数，此时根节点可以选，也可以不选（即包含奇数个子节点），此答案是一个满足题意要求的有效答案
# dp[i][0]: 表示子树节点为偶数，此时根节点必定不可选，否则不是一个有效答案
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = [0] * n
    g = [[] for _ in range(n)]
    for i in range(n):
        p, e = map(int, input().split())
        a[i] = e
        if i:
            p -= 1
            g[p].append(i)
    return n, a, g

def solve(n, a, g):
    dp = [[0, 0] for _ in range(n)]
    
    dfsStk = []
    i, childIndex = 0, 0
    while True:
        if childIndex == len(g[i]): 
            ma, mi, c = a[i], 1000001, 1
            for j in g[i]:
                e0, e1 = dp[j]
                if e0 >= e1:
                    ma, mi = ma + e0, min(mi, e0 - e1)
                else:
                    ma, mi, c = ma + e1, min(mi, e1 - e0), c ^ 1
            if c:
                dp[i][:] = ma - a[i], ma
            else:
                dp[i][:] = ma - a[i] - mi, ma - min(a[i], mi)

            if dfsStk:
                (i, childIndex) = dfsStk[-1]
                dfsStk.pop()
                continue 
            else:
                break
        
        j = g[i][childIndex]

        dfsStk.append((i, childIndex + 1))
        i, childIndex = j, 0
    return max(dp[0])

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
