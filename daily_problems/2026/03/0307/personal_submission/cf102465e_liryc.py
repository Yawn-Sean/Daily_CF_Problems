'''
https://codeforces.com/gym/102465/my#
'''
# math

pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
nor = lambda x: 0 if x < 0 else 10000 if x > 10000 else x
def solve(n: int, names: list[str], a: list[int]) -> list[str]:
    for i in range(n):
        a[i] *= 100
    lo = [nor(x - 50) for x in a]
    hi = [nor(x + 49) for x in a]
    lo_s, hi_s = sum(lo), sum(hi)
    if not lo_s <= 10000 <= hi_s:
        return ["IMPOSSIBLE"]
    for i in range(n):
        los, hos = lo_s - lo[i], hi_s - hi[i]
        lo[i] = pmax(lo[i], 10000 - hos)
        hi[i] = pmin(hi[i], 10000 - los)
    return [f"{names[i]} {lo[i] // 100}.{lo[i] % 100:02d} {hi[i] // 100}.{hi[i] % 100:02d}" for i in range(n)]
