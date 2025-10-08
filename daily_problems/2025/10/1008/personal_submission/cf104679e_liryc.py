'''
https://codeforces.com/gym/104679/submission/342520679
'''
# primes, binary search

# preset: 
# prime_set = /*list of all the primes*/
# def initPrimes(): ...
def solve(n: int) -> int:
    global prime_set
    if n <= 3: 
        return n - 2
    return bisect_right(prime_set, n) - bisect_right(prime_set, n >> 1)
