'''
https://codeforces.com/problemset/submission/980/310347325
'''
# 贪心
def solve(n: int, k: int, pa: list[int]) -> list[int]:
    a = list(range(256))
    for x in pa:
        if a[x] >= 0:
            z = x
            for y in range(x, max(-1, x - k), -1):
                if a[y] < 0:
                    t = ~a[y]
                    if t > x - k:
                        for z in range(y + 1, x + 1):
                            a[z] = ~t
                    break
                else:
                    z = y
            if a[x] >= 0:
                for y in range(z, x + 1):
                    a[y] = ~z
    return [~a[x] for x in pa]
