'''
https://codeforces.com/gym/106007/submission/349646899
'''
def solve(n: int, a: list[list[int]]) -> list[str]:
    pa = [-2] * n
    pa[0] = -1
    
    qu = deque()
    qu.append(0)
    stk = []
    while qu:
        u = qu.popleft()
        if u:
            stk.append(u)
        for v in range(n):
            if a[u][v] and pa[v] == -2:
                pa[v] = u
                qu.append(v)
    
    if len(qu) == n:
        ans = []
        for i in stk[::-1]:
            ans.append(f'{pa[i] + 1} {i + 1}')
        return ans
    else:
        return []
