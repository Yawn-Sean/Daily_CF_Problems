# Submission link: https://codeforces.com/contest/508/submission/327313370
def main():
    n = II()
    ls = []
    rs = []

    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)

    cur = -1
    ans = []

    def dfs(i):
        nonlocal cur
        ans.append('(')
        
        val = 1
        while val < ls[i] and cur + 1 < n:
            cur += 1
            val += dfs(cur)
        
        if not ls[i] <= val <= rs[i]:
            exit(print('IMPOSSIBLE'))
        
        ans.append(')')
        return val + 1

    while cur + 1 < n:
        cur += 1
        dfs(cur)

    print(''.join(ans))