# Submission link: https://codeforces.com/contest/818/submission/296908075
def main():
    n, k = MII()
    nums = LII()

    if k == 1:
        exit(print(n * (n + 1) // 2))

    primes = Counter()
    for i in range(2, k + 1):
        if k % i == 0:
            while k % i == 0:
                primes[i] += 1
                k //= i
        if i * i > k:
            break

    if k > 1: primes[k] += 1

    def check():
        for p in primes:
            if primes[p] > cur[p]:
                return False
        return True

    l, r = 0, 0
    cur = Counter()
    ans = 0

    while l < n:
        while r < n and not check():
            v = nums[r]
            for p in primes:
                while v % p == 0:
                    cur[p] += 1
                    v //= p
            r += 1
        
        if not check():
            break
        
        ans += n - r + 1
        
        v = nums[l]
        for p in primes:
            while v % p == 0:
                cur[p] -= 1
                v //= p
        
        l += 1

    print(ans)