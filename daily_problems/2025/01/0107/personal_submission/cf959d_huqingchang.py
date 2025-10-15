mx = 3 * 10 ** 6
primes = []
is_prime = [True] * (mx + 1)
is_prime[0] = is_prime[1] = False
for i in range(2, mx + 1):
    if is_prime[i]:
        primes.append(i)
    for p in primes:
        if p * i > mx: break
        is_prime[p * i] = False
        if i % p == 0: break


def main():
    n = II()
    res = LII()
    used = set()

    def check(y):
        candiUsed = []
        if is_prime[y]:
            if y not in used:
                used.add(y)
                return True
            return False
        for p in primes:
            if p ** 2 > y:
                break
            if y % p == 0:
                if p in used:
                    return False
                candiUsed.append(p)
                while y % p == 0:
                    y //= p
        if y in used:
            return False
        if y != 1:
            used.add(y)
        for candi in candiUsed:
            used.add(candi)
        return True

    def getNext(y):
        for c in count(y + 1):
            if check(c):
                return c

    ans = []
    for x in res:
        if check(x):
            ans.append(x)
        else:
            ne = getNext(x)
            ans.append(ne)
            i = 0
            need = n - len(ans)
            while need:
                while primes[i] in used:
                    i += 1
                ans.append(primes[i])
                i += 1
                need -= 1
            break
    exit(print(*ans))


T = 1
for ii in range(T):
    # print(main())
    main()
