'''
https://codeforces.com/problemset/submission/818/320868048
'''
# construction of permutations
def solve(n: int, m: int, la: list[int]) -> int:
    for i in range(m):
        la[i] -= 1
    ans = [-1] * n
    hs = [False] * (n + 1)
    for i, j in pairwise(la):
        d = j - i
        if d <= 0:
            d += n
        if ans[i] > 0 and ans[i] != d:
            return [-1]
        elif ans[i] < 0:
            if hs[d]:
                return [-1]
            ans[i] = d
            hs[d] = True
    j = 1
    for i in range(n):
        if ans[i] < 0:
            while hs[j]:
                j += 1
            ans[i] = j
            hs[j] = True

    return ans
