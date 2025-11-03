'''
https://codeforces.com/gym/106073/submission/346902488
'''
def solve(n: int, q: int, a: list[int]) -> list[int]:
    MOD = 1000000007
    inv_of_2 = pow(2, -1, MOD)
    ans = [0] * n
    c = 0
    for x in a[::-1]:
        ans[x - 1] = (ans[x - 1] + c * inv_of_2) % MOD
        c = (c + x) * inv_of_2 % MOD
    ans[0] = (ans[0] + c) % MOD
    return ans
