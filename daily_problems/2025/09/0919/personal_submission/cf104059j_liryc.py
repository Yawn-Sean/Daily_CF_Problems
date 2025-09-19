'''
https://codeforces.com/gym/104059/submission/339377220
'''
def solve(s: str) -> int:
    n = 0
    for p in permutations('hdcs'):
        d0, d1, d2, d3 = 0, 0, 0, 0
        for c in s:
            if p[0] == c:
                d0 += 1
            elif p[1] == c:
                d1 += 1
            elif p[2] == c:
                d2 += 1
            else:
                d3 += 1
            d1 = max(d1, d0)
            d2 = max(d2, d1)
            d3 = max(d3, d2)
        n = max(n, d3)
    return len(s) - n

