'''
https://codeforces.com/gym/105790/submission/354557776
'''
MOD = 998244353

def multiply(a, b):
    global MOD
    return [
        [(a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD,
            (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD],
        [(a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD,
            (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD]
    ]

def matrix_pow(mat, power):
    global MOD
    result = [[1, 0], [0, 1]]  
    while power:
        if power & 1:
            result = multiply(result, mat)
        mat = multiply(mat, mat)
        power >>= 1
    return result

def solve(n: int) -> int:  
    global MOD
    if n == 0:
        return 1
    MOD -= 1
    e = matrix_pow([[1, 1], [1, 0]], n - 1)[0][0]
    MOD += 1
    return pow(2, e, MOD)
