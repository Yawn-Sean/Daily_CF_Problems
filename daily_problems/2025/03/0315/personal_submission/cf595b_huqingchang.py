mod = 10 ** 9 + 7
# rnd = random.getrandbits(30)

def main():
    n, k = MII()
    a, b = LII(), LII()
    ans = 1
    cst1 = 10 ** k
    cst2 = 10 ** (k - 1)

    def f(ai, bi):
        tmp = 0
        if bi:
            tmp += (bi * cst2 + ai - 1) // ai
        if bi != 9:
            fir = ((bi + 1) * cst2 + ai - 1) // ai * ai
            if fir < cst1:
                tmp += (cst1 - fir + ai - 1) // ai
        return tmp

    for i in range(len(a)):
        ans *= f(a[i], b[i])
        ans %= mod
        if not ans:
            return 0
    return ans


T = 1
for ii in range(T):
    print(main())
