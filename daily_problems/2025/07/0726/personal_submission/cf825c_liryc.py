'''
https://codeforces.com/problemset/submission/825/330890892
'''
# sorting, greedy
def solve(n: int, k: int, a: list[int]) -> int:
    ans = 0
    a.sort()
    for x in a:
        if x > k:
            while x > k << 1:
                ans += 1
                k <<= 1
            if x > k:
                k = x
    return ans
