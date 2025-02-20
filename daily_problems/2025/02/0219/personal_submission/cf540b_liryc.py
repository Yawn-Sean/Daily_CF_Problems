'''
https://codeforces.com/problemset/submission/540/306874558
'''
# 可以直接算出还需要多少个小于y的和大于等于y的，分别填1和y，然后验证
def solve(n: int, k: int, p: int, x: int, y: int, a: list[int]) -> list[int]:
    nlow, nhigh = sum(1 for m in a if m < y), sum(1 for m in a if m >= y)
    if nlow >= (n + 1 >> 1):
        return [-1]
    ans = [1] * min((n >> 1) - nlow, n - len(a)) + [y] * ((n + 1 >> 1) - nhigh)
    if sum(a) + sum(ans) > x:
        return [-1]
    return ans
