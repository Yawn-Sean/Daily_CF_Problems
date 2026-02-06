'''
https://codeforces.com/gym/104020/submission/361633863
'''
def solve(n: int, a: list[list[int]]) -> float:
    a.sort()
    ans = (1 << 62) - 1 << 1
    for i in range(n):
        x1, y1, z1 = a[i]
        for j in range(pmax(i - 100, 0), i):
            x2, y2, z2 = a[j]
            ans = pmin(ans, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1))
    return ans ** 0.5

