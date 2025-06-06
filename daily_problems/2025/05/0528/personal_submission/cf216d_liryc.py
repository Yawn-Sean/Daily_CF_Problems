'''
https://codeforces.com/problemset/submission/216/321783779
'''
# array, range, binary search   
def solve(n: int, ka: list[list[int]]) -> int:
    for i in range(n):
        ka[i][0] = 0
        ka[i].sort()
    ans = 0
    for i in range(n):
        pv, nt = ka[i - 1], ka[i - n + 1]
        for l, r in pairwise(ka[i]):
            if l == 0: 
                continue
            p1 = bisect_left(pv, l)
            p2 = bisect_right(pv, r)
            n1 = bisect_left(nt, l)
            n2 = bisect_right(nt, r)
            if p2 - p1 != n2 - n1:
                ans += 1
    return ans
