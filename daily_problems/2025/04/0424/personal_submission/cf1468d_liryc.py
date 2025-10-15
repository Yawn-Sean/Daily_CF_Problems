'''
https://codeforces.com/problemset/submission/1468/316917357
'''
# sort + greedy
def solve(n: int, m: int, a: int, b: int, s: list[int]) -> int:
    k, t = 0, 0
    if a < b:
        k, t = b - a - 1, a - 1
    else:
        k, t = a - b - 1, n - a
    if k == 0:
        return 0
    s.sort()
    ans = 0
    for x in s[::-1]:
        if x <= k + t:
            ans += 1
            k -= 1
            if k == 0:
                break
    return ans
