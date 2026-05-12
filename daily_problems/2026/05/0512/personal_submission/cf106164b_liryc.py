'''
https://codeforces.com/gym/106164/submission/374260460
greedy
'''
def solve(n: int, m: int) -> list[int]:
    if n == 2:
        if m & 1: 
            return [2, 1]
        else: 
            return [1, 2]
    elif m >= n:
        return list(range(n, 0, -1))
    else:
        return list(range(n, n - m, -1)) + list(range(1, n - m + 1))
