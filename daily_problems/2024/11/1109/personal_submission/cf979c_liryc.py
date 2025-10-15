'''
https://codeforces.com/problemset/submission/979/290703039
979C
2024/11/9 Y1
1600
Tree Dfs
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, x, y = map(int, input().split())
    x, y = x - 1, y - 1
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        a, b = a - 1, b - 1
        g[a].append(b)
        g[b].append(a)
    return n, x, y, g

def solve(n: int, x: int, y: int, tg: list[list[int]]) -> int:
    cn = [0] * n
    cx, cy = 0, 0
    dfsStk = []
    i, childIndex = x, 0
    while True:
        if childIndex == len(tg[i]): 
            parent = dfsStk[-1][0] if dfsStk else -1

            # dfs out
            if i == x:
                cx = 1 + sum(cn[t] for t in tg[x])
            else:
                cn[i] = 1
                for j in tg[i]:
                    if j != parent:
                        if cn[j] == 0:
                            cn[i] = 0
                            break
                        else:
                            cn[i] += cn[j]
                if i == y:
                    cy = cn[i]
                    cn[i] = 0

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

    return n * (n - 1) - cx * cy

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
