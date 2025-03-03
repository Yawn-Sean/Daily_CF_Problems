def main():
    prime_factor = list(range(200001))
    for i in range(2, 200001):
        if prime_factor[i] == i:
            for j in range(i, 200001, i):
                prime_factor[j] = min(prime_factor[j], i)

    t = II()
    outs = []

    for i in range(t):
        x, y = MII()
        if x == 1 or y == 1: outs.append(-1)
        else:
            ans = prime_factor[x] * prime_factor[y]
            g = math.gcd(x, y)
            if g > 1:
                ans = min(ans, prime_factor[g])
            outs.append(ans)

    print('\n'.join(map(str, outs)))