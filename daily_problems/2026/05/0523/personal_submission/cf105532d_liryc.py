'''
https://codeforces.com/gym/105532/submission/375740657
simple greedy
'''
def solve(n: int, pa: list[list[int]]) -> int:
    for i in range(n):
        if pa[i][0] < pa[i][1]:
            pa[i][:] = pa[i][::-1]
    pa.sort(reverse=True)
    ans, s = 0, 0

    for w, h in pa:
        s += h
        ans = max(ans, min(w, s))

    return ans
