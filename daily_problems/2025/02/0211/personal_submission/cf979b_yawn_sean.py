# Submission link: https://codeforces.com/contest/979/submission/305533723
def main():
    def f():
        s = I()
        k = len(s)
        c = Counter(s).most_common()[0][1]
        if c + n <= k: return c + n
        if c == k and n == 1: return fmax(1, k - 1)
        return k

    n = II()
    v1 = f()
    v2 = f()
    v3 = f()

    if v1 > v2 and v1 > v3: print('Kuro')
    elif v2 > v1 and v2 > v3: print('Shiro')
    elif v3 > v1 and v3 > v2: print('Katie')
    else: print('Draw')