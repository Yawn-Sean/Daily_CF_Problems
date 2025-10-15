def main():
    x2 = II()
    primes = []
    mi_prime_factor = list(range(x2 + 1))
    for i in range(2, x2 + 1):
        if mi_prime_factor[i] == i:
            primes.append(i)
        for p in primes:
            tmp = p * i
            if tmp > x2:
                break
            mi_prime_factor[tmp] = p
            if i % p == 0:
                break

    def f(x):  # x是个合数，寻找它的前一个数最小可能值
        a = 0
        up = x
        while x > 1:
            a = x
            x //= mi_prime_factor[x]
        return up - a + 1

    low = f(x2)
    ans = inf
    for i in range(low, x2 + 1):
        if mi_prime_factor[i] == i:
            continue
        ans = min(ans, f(i))
    return ans


T = 1
for ii in range(T):
    print(main())
