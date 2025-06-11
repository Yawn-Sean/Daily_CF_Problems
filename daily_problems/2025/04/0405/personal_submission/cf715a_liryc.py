'''
https://codeforces.com/problemset/submission/715/313994286
'''
def solve(n: int) -> list[int]:
    ans = []
    ans.append(2)
    for i in range(2, n + 1):
        ans.append(i * i * i + 2 * i * i + 1)
    return ans
