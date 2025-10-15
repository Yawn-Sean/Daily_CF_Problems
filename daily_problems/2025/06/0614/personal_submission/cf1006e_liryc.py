'''
https://codeforces.com/problemset/submission/1006/324316124
'''
# DFS timestamp
def solve(n: int, q: int, parents: list[int], queries: list[list[int]]) -> list[int]:
    tg = [[] for _ in range(n)]
    for i, p in enumerate(parents):
        tg[p - 1].append(i + 1)
    dfs_index = [0] * n
    dfs_seq = [0] * n
    tree_size = [0] * n
    stk, i = [0], 0
    while stk:
        cur = stk.pop()
        if cur < 0:
            cur = ~cur
            tree_size[cur] = 1 + sum(tree_size[child] for child in tg[cur])
        else:
            stk.append(~cur)
            dfs_seq[i] = cur
            dfs_index[cur] = i
            i += 1
            stk += tg[cur][::-1]
    
    def qry(u, k):
        nonlocal dfs_index, dfs_seq, tree_size
        u -= 1
        if k > tree_size[u]:
            return -1
        return dfs_seq[dfs_index[u] + k - 1] + 1
    
    return [qry(u, k) for u, k in queries]
