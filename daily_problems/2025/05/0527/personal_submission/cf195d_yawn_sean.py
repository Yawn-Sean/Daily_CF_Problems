# Submission link: https://codeforces.com/problemset/submission/195/321567874
def main():
    n = II()
    vis = set()

    for _ in range(n):
        k, b = MII()
        g = math.gcd(k, b)
        if k:
            k //= g
            b //= g
            if k < 0 or (k == 0 and b < 0):
                k = -k
                b = -b
            vis.add((k, b))

    print(len(vis))