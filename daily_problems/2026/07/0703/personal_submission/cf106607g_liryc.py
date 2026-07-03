'''
https://codeforces.com/gym/106607/submission/381084802
greedy, cases
'''
def solve(n: int, m: int, k: int) -> int:
    if k <= n:
        return k
    elif m & 1:
        return n - (n & 1 ^ k & 1)
    elif k > (m - 1) * n: 
        return n - (k - (m - 1) * n)
    else:
        r = (k - n) % (m - 2)
        return n - (r & 1)
