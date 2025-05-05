'''
https://codeforces.com/problemset/submission/89/318428458
'''
def solve(n: int, m: int, k: int, a: list[int]) -> int:
    if n & 1:
        ans1 = min(a[::2])
        ans2 = m // (n // 2 + 1) * k
        return ans1 if ans1 < ans2 else ans2
    else:
        return 0
