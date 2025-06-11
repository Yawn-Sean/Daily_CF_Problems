'''
https://codeforces.com/problemset/submission/963/291274524
963B
2024/11/13 Y2
2000
Tree Dfs, constructive
'''
# 遗留问题：为什么从任意节点作为根节点出发都能得到结果？（能理解但不能证明）

from collections import deque
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    g = [[] for _ in range(n + 1)]
    a = list(map(int, input().split()))
    for i, x in enumerate(a):
        if x:
            y = i + 1
            g[y].append(x)
            g[x].append(y)
    return n, g

def solve(n: int, tg: list[list[int]]):
    if not n & 1:
        return []
    ans = []
    degree = [False] * (n + 1) 
        # child degree=1 -> remove later
        # current degree=1 -> remove immediately + remove children with degree 1
    dfsStk = []
    i, childIndex = 1, 0
    while True:
        if childIndex == len(tg[i]): 
            parent = dfsStk[-1][0] if dfsStk else -1

            # dfs out
            dc = sum(degree[j] for j in tg[i] if j != parent)
            if i == 1 or (dc & 1): 
                # BFS to perform removing
                dq = deque()
                dq.append((i, -1))
                while dq:
                    j, p = dq.popleft()
                    ans.append(j)
                    for chld in tg[j]:
                        if chld != p and degree[chld]:
                            dq.append((chld, j))
            else:
                degree[i] = True

            if dfsStk:
                (i, childIndex) = dfsStk[-1]
                dfsStk.pop()
                continue 
            else:
                break
        # elif childIndex == 0:
        #     ## dfs in 
        #     pass
        
        j = tg[i][childIndex]

        if dfsStk and dfsStk[-1][0] == j: # skip parent
            childIndex += 1
            continue
        else:
            # recursion
            dfsStk.append((i, childIndex + 1))
            i, childIndex = j, 0
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print("YES")
        print(*ans, sep='\n')
    else:
        print("NO")
