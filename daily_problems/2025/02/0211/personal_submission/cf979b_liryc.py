'''
https://codeforces.com/problemset/submission/979/305613448
'''
# counter
def solve(n: int, ku: str, sh: str, ka: str) -> str:
    m = len(ku)
    def getc(s):
        nonlocal n, m
        if m == 1:
            return 1
        c = max(Counter(s).values())
        if c == m and n == 1:
            return m - 1
        return min(c + n, m)
    
    c1 = getc(ku)
    c2 = getc(sh)
    c3 = getc(ka)
    if c1 > c2 and c1 > c3:
        return "Kuro"
    if c2 > c1 and c2 > c3:
        return "Shiro"
    if c3 > c1 and c3 > c2:
        return "Katie"
    return "Draw"
