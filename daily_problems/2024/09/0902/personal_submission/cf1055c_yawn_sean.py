# Submission link: https://codeforces.com/contest/1055/submission/279265529
def main():
    la, ra, ta = MII()
    lb, rb, tb = MII()

    a = ra - la + 1
    b = rb - lb + 1

    g = math.gcd(ta, tb)
    x = la - lb
    x %= g

    print(max(0, fmin(x + a, b) - x, fmin(x - g + a, b)))