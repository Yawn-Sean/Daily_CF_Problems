def main():
    n = II()
    nums = LII()
    
    pt = PrimeTable(2*10**6)
    primes = set(pt.primes)
    
    ans = []
    used = set()
    p = -1
    quit = 0
    for i, num in enumerate(nums):
        for pi, _ in pt.prime_factorization(num):
            if pi in used:
                p = i
                quit = 1
                break
        else:
            for pi, _ in pt.prime_factorization(num):
                used.add(pi)
                primes.remove(pi)
            ans.append(num)
    
        if quit == 1:
            break
    
    
    
    if p != -1:
        e = nums[p]
        while True:
            for pi, _ in pt.prime_factorization(e):
                if pi in used:
                    e += 1
                    break
            else:
                ans.append(e)
                for pi, _ in pt.prime_factorization(e):
                    used.add(pi)
                    primes.remove(pi)
                break
    
        primes = list(sorted(primes, reverse=True))
        while len(ans) < n:
            ans.append(primes.pop())
    
    print(" ".join(map(str, ans)))
