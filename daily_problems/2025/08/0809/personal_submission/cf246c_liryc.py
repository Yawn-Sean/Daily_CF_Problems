'''
https://codeforces.com/problemset/submission/246/333131716
'''
# enumeration
def solve(n: int, k: int, a: list[int]) -> list[list[int]]:
    ans = []
    a.sort()
    for j in range(n, 0, -1):
        for i in range(j):
            ans.append([a[i]] + [a[c] for c in range(j, n)])
            if len(ans) == k:
                return ans
