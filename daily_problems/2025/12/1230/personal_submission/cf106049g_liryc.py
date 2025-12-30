'''
https://codeforces.com/gym/106049/submission/355857531
'''
def solve(n: int, l: int, r: int) -> list[list[int]]:
    global fac, MOD
    m = n // l
    if m * r < n:
        return []
    ans = [[l, 0] for _ in range(m + 1)]
    v = n - l * m
    begin, end = 0, n
    for i in range(-1, -m - 1, -1):
        d = min(r, l + v)
        v -= d - l
        begin = end - d
        ans[i][:] = begin + 1, end
        end = begin
    ans[0][:] = m, fac[ans[1][1]]
    return ans
