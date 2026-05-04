'''
https://codeforces.com/gym/106511/submission/373428521
'''
def solve(n: int) -> int:
    ans = 0
    b = 1
    while b * 10 <= n:
        ans += 1
        b *= 10
    
    for d in range(1, 10):
        b = 0
        while b * 10 + d <= n:
            b = b * 10 + d
            ans += 1

    return ans
    