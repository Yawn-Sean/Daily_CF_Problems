'''
https://codeforces.com/gym/106494/submission/372190911
'''

def solve(n: int, a: list[int]) -> int:
    a.sort()
    ans = c = sum(a) << 1
    for i, x in enumerate(a):
        c -= x << 1
        ans = max(ans, c + a[i >> 1] + a[i + 1 >> 1])
    return ans
