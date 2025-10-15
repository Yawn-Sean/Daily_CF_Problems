'''
https://codeforces.com/gym/104772/submission/339214051
'''
# 费马小定理，欧拉定理
def solve(d: int) -> str:
    x, n9, n2, n5, n10 = 9, 1, 0, 0, 0
    t = d
    while t & 1 == 0:
        n2 += 1
        t >>= 1
    while t % 5 == 0:
        n5 += 1
        t //= 5
    n10 = n5 if n5 > n2 else n2
    x %= t
    while x:
        n9 += 1
        x = (x * 10 + 9) % t
    return '9' * lcm(n9, d) + '0' * n10
