'''
https://codeforces.com/problemset/submission/768/319321278
'''
# array + sort

def solve(n: int, k: int, x: int, a: list[int]) -> list[int]:
    aa, ba = [0] * 1024, [0] * 1024
    for y in a:
        aa[y] += 1
    for _ in range(k):
        p = 0
        for y, c in enumerate(aa):
            d1, d2 = c + 1 >> 1, c >> 1
            if p & 1:
                ba[y ^ x] += d2
                ba[y] += d1
            else:
                ba[y ^ x] += d1
                ba[y] += d2
            p += c
        aa, ba = ba, aa
        ba[:] = repeat(0, 1024)
    ans = [0, 0]
    for y in range(1023, -1, -1):
        if aa[y]:
            ans[0] = y
            break
    for y in range(1024):
        if aa[y]:
            ans[1] = y
            break
    return ans
