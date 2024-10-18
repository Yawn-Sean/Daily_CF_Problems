'''
https://codeforces.com/contest/1833/submission/268279189
1833 G
2024/7/1 Y1
1800
Tree postorder DFS
'''

def init():
    n = int(input())
    tg = [[] for _ in range(n)]
    for i in range(1, n):
        u, v = map(int, input().split())
        tg[u - 1].append((v - 1, i))
        tg[v - 1].append((u - 1, i))
    return n, tg

def solve(n, tg):
    ans = []
    cn = [0] * n
    dfsStk = []
    i, childIndex = 0, 0
    while True:
        if childIndex == len(tg[i]): 
            parent = -1 if i <= 1 else dfsStk[-1][0]
            
            cn[i] = 1
            for j, e in tg[i]:
                if j != parent:
                    if cn[j] == -1:
                        ans.append(e)
                    else:
                        cn[i] += cn[j]
            if cn[i] > 3:
                return [-1]
            elif cn[i] == 3:
                cn[i] = -1

            if dfsStk:
                (i, childIndex) = dfsStk[-1]
                dfsStk.pop()
                continue 
            else:
                break
        
        j, e = tg[i][childIndex]

        if dfsStk and dfsStk[-1][0] == j: # skip parent
            childIndex += 1
            continue
        else:
            dfsStk.append((i, childIndex + 1))
            i, childIndex = j, 0
    if cn[0] != -1:
        return [-1]
    ans.sort()
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        if ans and ans[0] == -1:
            print(-1)
        else:
            print(len(ans))
            if ans:
                print(*ans)
            else:
                print()
