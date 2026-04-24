'''
https://codeforces.com/gym/106495/submission/372303297
'''
def solve(n: int, q: int, qa: list[int]) -> list[int]:
    global MAXN
    MAXN = n + 1
    initPrimes()
    m = len(prime_set)
    enc = lambda x, y: x << 17 | y
    dec = lambda z: (z >> 17, z & (1 << 17) - 1)
    sa = []
    stk = [enc(1, 0)]
    while stk:
        x, i = dec(stk.pop())
        sa.append(x)
        pa = []
        for j in range(i, m): 
            y = x * prime_set[j]
            if y <= n:
                pa.append(enc(y, j))
            else:
                break
        stk.extend(reversed(pa))
    return [sa[k - 1] for k in qa]
