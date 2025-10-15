'''
https://codeforces.com/problemset/submission/690/328071426
'''
# combinations
# 例如 n=3, c=4, 依次枚举n=0,1,2,3的情况，答案为
# 1, C(4,1), C(5,2), C(6,3)
# 以上四个加起来等于C(7,3)
# 所以答案为C(n+C, n)，然后题目不算n=0，所以减1
def solve(n: int, c: int) -> int:
    MOD = 1000003
    c1 = 1
    c2 = 1
    for i in range(1, n + 1):
        c1 = c1 * (n + c + 1 - i) % MOD
        c2 = c2 * i % MOD
    return (c1 * pow(c2, -1, MOD) % MOD - 1) % MOD