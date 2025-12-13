'''
https://codeforces.com/gym/105284/submission/353318856
'''
ps = [0] * (1000001)
MOD = 1000000007
fac = Factorial(1000000, MOD)

def init(): 
    global ps, MOD, fac
    for x in range(1, 1000001):
        ps[x] = (ps[x - 1] + fac.inv(x)) % MOD

def solve(n: int) -> int:
    global ps, MOD, fac
    return (ps[n] - (1 - fac.inv(n))) % MOD
