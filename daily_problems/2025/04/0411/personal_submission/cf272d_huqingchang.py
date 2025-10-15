rnd = random.getrandbits(30)

def main():
    n = II()
    A, B = LII(), LII()
    mod = II()
    ans, c = 1, 0
    cnt = Counter()
    for i in range(n):
        cnt[A[i] ^ rnd] += 1
        cnt[B[i] ^ rnd] += 1
        if A[i] == B[i]:
            c += 1
    for v in cnt.values():
        for i in range(2, v + 1):
            while c and i & 1 == 0:
                c -= 1
                i //= 2
            ans = ans * i % mod 
    return ans


T = 1
for ii in range(T):
    # print(ii)
    print(main())
