'''
https://codeforces.com/gym/103821/submission/381541154
math
'''

MAXN = 10 ** 5 + 4
MOD = 10 ** 9 + 7
hf = [0] * MAXN # hf[n] = n! / 2
pa = [1] * MAXN # prefix sum of factor counts
def initData():
    global hf, fc
    hf[1] = hf[2] = 1
    for n in range(3, MAXN):
        hf[n] = hf[n - 1] * n % MOD
    pa[0] = pa[1] = 0
    for f in range(2, MAXN + 2 >> 1):
        for n in range(f + f, MAXN, f):
            pa[n] += 1
    for n in range(1, MAXN):
        pa[n] += pa[n - 1]

def solve(n: int) -> int:
    return pa[n] * hf[n] % MOD
