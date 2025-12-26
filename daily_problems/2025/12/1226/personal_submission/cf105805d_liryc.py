'''
https://codeforces.com/gym/105805/submission/355124144
'''
def solve(n: int, a: list) -> list[int]:
    ft = FenwickTree(n + 1)
    r = 0
    b = []
    for x in a:
        u = ft.rsum(x + 1, n)
        v = ft.rsum(0, x - 1)
        r += u
        b.append(v - u)
        ft.add(x, 1)
    b.sort()
    ans = [r]
    for x in b:
        ans.append(ans[-1] + x)
    return ans

