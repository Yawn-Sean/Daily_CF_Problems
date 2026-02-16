'''
https://codeforces.com/contest/2195/submission/363225778
'''
# linear equations
def solve(n: int, f: list[int]) -> list[int]:
    s = (f[0] + f[-1]) // (n - 1) # s = a1 + a2 + ... + a[n]
    ps = 0 # prefix sum
    a = [0] * n
    for i in range(n - 1):
        a[i] = (f[i + 1] - f[i] + s >> 1) - ps
        ps += a[i]
    a[-1] = s - ps
    return a
