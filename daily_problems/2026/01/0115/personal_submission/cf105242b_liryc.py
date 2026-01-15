'''
https://codeforces.com/gym/105242/submission/357918576
'''
# tree dp
def solve(n: int, tg: list[list[int]]) -> bool:
    root = -1
    for u in range(n):
        du = len(tg[u])
        if du > 3:
            return False
        elif root < 0 and du == 3:
            root = u
    if root < 0:
        return True
    stk = [root]
    pr = [-1] * n
    for u in stk:
        for v in tg[u]:
            if v != pr[u]:
                pr[v] = u
                stk.append(v)
    dp = [0] * n
    for u in stk[::-1]:
        c = sum(dp[v] for v in tg[u] if v != pr[u])
        if u == root:
            if c > 2:
                return False
        else:
            if c > 1:
                return False
            dp[u] = c or len(tg[u]) == 3
    return True
