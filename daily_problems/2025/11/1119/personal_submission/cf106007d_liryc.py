'''
https://codeforces.com/gym/106007/submission/349680751
'''
def solve(n: int, a: list[list[int]]) -> list[str]:
    pa = [-1] * n
    qu = deque()
    qu.append(0)
    stk = []
    while qu:
        u = qu.popleft()
        if u:
            stk.append(u)
        for v in range(1, n):
            if a[u][v] and pa[v] < 0:
                pa[v] = u
                qu.append(v)
    if len(stk) == n - 1:
        ans = []
        for i in stk[::-1]:
            ans.append(f'{pa[i] + 1} {i + 1}')
        return ans
    else:
        return []
