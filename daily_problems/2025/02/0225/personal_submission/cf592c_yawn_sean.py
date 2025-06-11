# Submission link: https://codeforces.com/contest/592/submission/307598830
def main():
    t, w, b = MII()
    l = math.lcm(w, b)

    x, y = divmod(t, l)
    mi = fmin(w, b)
    p, q = x * mi + fmin(mi - 1, y), t
    g = math.gcd(p, q)

    print(p // g, '/', q // g, sep='')