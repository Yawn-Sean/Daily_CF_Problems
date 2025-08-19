'''
https://codeforces.com/problemset/submission/1970/334498578
'''
def solve(n: int, a: list[int]) -> list[list[int]]:
    ans = []
    for i in range(n):
        ans.append([i + 1, i + 1])
    ans.append([i + x // 2 + 1 if i + x // 2 < n else i - x // 2 + 1 for i, x in enumerate(a)])
    return ans
