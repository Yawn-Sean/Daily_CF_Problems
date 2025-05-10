'''
https://codeforces.com/problemset/submission/877/318902975
'''
# find rules
def solve(n: int) -> list[int]:
    ans = []
    ans.extend(range(2, n + 1, 2))
    ans.extend(range(1, n + 1, 2))
    ans.extend(range(2, n + 1, 2))
    return ans
