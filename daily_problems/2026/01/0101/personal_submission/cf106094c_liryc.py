'''
https://codeforces.com/gym/106094/submission/355991527
'''
# primes
def solve(x: int, k: int):
    a = []
    p = -1
    for f in prime_elements(x):
        if f == p:
            a[-1] += 1
        else:
            p = f
            a.append(1)
    for e in range(1, 100):
        c = 0
        d = 1 << e
        for n in a:
            c += -n % d
            if c > k:
                return e - 1
