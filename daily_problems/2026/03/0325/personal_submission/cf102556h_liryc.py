'''
20260325 T1 1600
'''
def solve(m: int) -> int: 
    if m == 1:
        return 1
    cnt = Counter()
    for x in range(2, 4 * 10 ** 7):
        while m % x == 0:
            cnt[x] += 1
            m //= x
    if m > 1:
        cnt[m] += 1
    g = 0
    for x in cnt.values():
        g = gcd(g, 2 * x)
    for i in range(1, g + 1):
        if g % i == 0:
            fc = 1
            for x in cnt:
                fc *= 1 + 2 * cnt[x] // g * i
            if i * fc == g:
                ans = 1
                for x in cnt:
                    ans *= pow(x, 2 * cnt[x] // g * i)
                return ans
    return -1