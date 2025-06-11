# Submission link: https://codeforces.com/contest/396/submission/294280531
def main():
    def isPrime(x):
        for i in range(2, x):
            if i * i > x: break
            if x % i == 0: return False
        return True

    t = II()
    outs = []

    for _ in range(t):
        n = II()
        l = n
        while not isPrime(l):
            l -= 1
        r = l + 1
        while not isPrime(r):
            r += 1
        a = r * l - 2 * r + 2 * (n - l + 1)
        b = 2 * r * l
        g = math.gcd(a, b)
        a //= g
        b //= g
        outs.append(f'{a}/{b}')

    print('\n'.join(outs))