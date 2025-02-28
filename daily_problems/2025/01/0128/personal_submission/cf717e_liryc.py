'''
https://codeforces.com/problemset/submission/717/303383935
'''
# tree dfs
def solve(n: int, color: list[bool], tg: list[list[int]]) -> list[int]:
    a = [False] * n # a[u] == true when all subtrees are black, otherwise false
    color[0] = not color[0] 
    ans = []
    # dfs1
    stk = []
    stk.append((0, -1))
    while stk:
        i, parent = stk.pop()
        if i < 0:
            i = ~i
            a[i] = color[i] and all(a[j] for j in tg[i] if j != parent)
        else:
            stk.append((~i, parent))
            for j in tg[i]:
                if j != parent:
                    stk.append((j, i))
    # dfs2
    stk.append((0, -1))
    while stk:
        i, parent = stk.pop()
        ans.append(i + 1)
        color[i] = not color[i]
        a[i] = color[i] and all(a[j] for j in tg[i] if j != parent)
        for j in tg[i]:
            if j != parent and not a[j]:
                stk.append((i, parent))
                stk.append((j, i))
                break

    if not color[0]:
        ans.append(tg[0][0] + 1)
        ans.append(1)
        ans.append(tg[0][0] + 1)

    return ans
