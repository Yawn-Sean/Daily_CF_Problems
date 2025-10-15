'''
https://codeforces.com/problemset/submission/327/319709565
'''
def solve(a: str, k: int) -> int:
    MOD = 1000000007
    ls = len(a)
    p, sm = 1, 0
    for i in range(ls):
        if a[i] == '0' or a[i] == '5':
            sm += p
        p = p * 2 % MOD
    return sm * (pow(2, ls * k, MOD) - 1) % MOD * pow(pow(2, ls, MOD) - 1, -1, MOD) % MOD
