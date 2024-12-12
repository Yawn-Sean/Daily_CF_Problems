# Submission link: https://codeforces.com/contest/1142/submission/296086170
def main():
    n, k = MII()
    a, b = MII()

    v = n * k

    mi, ma = n * k, 0

    for i in range(n):
        x = i * k + a - b
        res = v // math.gcd(v, x)
        if res < mi: mi = res
        if res > ma: ma = res
        x = i * k + a + b
        res = v // math.gcd(v, x)
        if res < mi: mi = res
        if res > ma: ma = res

    print(mi, ma)