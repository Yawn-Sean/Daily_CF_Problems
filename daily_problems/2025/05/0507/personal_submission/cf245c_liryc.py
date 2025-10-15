'''
https://codeforces.com/problemset/submission/245/318733315
'''
# binary tree, greedy
def solve(n: int, a: list[int]):
    if n == 1 or not n & 1:
        return -1
    ans = 0
    for r in range(n - 1, -1, -1):
        if r + 1 << 1 < n:
            d = max(a[r << 1 | 1], a[r + 1 << 1])
            a[r << 1 | 1] = a[r + 1 << 1] = 0
            a[r] = max(a[r] - d, 0)
            ans += d
    if a[0]:
        ans += a[0]
    return ans
