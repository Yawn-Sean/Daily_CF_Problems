'''
https://codeforces.com/gym/103451/submission/362079981
'''
# boolean logic + counting
def solve(n: int, a: str, b: str, c: str) -> int:
    MOD = 1000000007
    M = pow(2, n - 1, MOD)
    ans = 1
    for x, y, z in zip(a, b, c):
        is_and = x == '1'
        is_or = y == '1'
        is_xor = z == '1'
        if is_and: 
            if not is_or or is_xor != (n & 1):
                return 0
        elif not is_or:
            if is_and or is_xor:
                return 0
        elif n == 1:
            return 0 
        else:
            m = M
            if is_xor == n & 1:
                m -= 1
            if not is_xor:
                m -= 1
            ans = ans * m % MOD
    return ans
