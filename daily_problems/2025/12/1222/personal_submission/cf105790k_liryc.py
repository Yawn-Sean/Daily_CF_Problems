'''
20251222_Y1
'''
def solve(n: int) -> int:  
    MOD = 998244353
    return pow(2, matrix_pow([[1, 1], [1, 0]], n, MOD - 1)[0][1], MOD)