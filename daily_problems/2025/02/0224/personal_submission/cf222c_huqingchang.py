def main():
    n, m = MII()
    mx = 10 ** 7
    mi_prime_factor = list(range(mx + 1))
    primes = []
    for i in range(2, mx + 1):
        if mi_prime_factor[i] == i:
            primes.append(i)
        for p in primes:
            tmp = p * i
            if tmp > mx:
                break
            mi_prime_factor[tmp] = p
            if i % p == 0:
                break

    def f(lis):
        ret = [0] * (mx + 1)
        for x in lis:
            while x > 1:
                ret[mi_prime_factor[x]] += 1
                x //= mi_prime_factor[x]
        return ret

    nums1, nums2 = LII(), LII()
    cnt1, cnt2 = f(nums1), f(nums2)
    for p in primes:
        cnt1[p] = min(cnt1[p], cnt2[p])
        cnt2[p] = cnt1[p]
    for i, j in enumerate(nums1):
        x = j
        while j > 1:
            if cnt1[mi_prime_factor[j]]:
                cnt1[mi_prime_factor[j]] -= 1
                x //= mi_prime_factor[j]
            j //= mi_prime_factor[j]
        nums1[i] = x
    for i, j in enumerate(nums2):
        x = j
        while j > 1:
            if cnt2[mi_prime_factor[j]]:
                cnt2[mi_prime_factor[j]] -= 1
                x //= mi_prime_factor[j]
            j //= mi_prime_factor[j]
        nums2[i] = x
    print(n, m)
    print(*nums1)
    print(*nums2)


T = 1
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
