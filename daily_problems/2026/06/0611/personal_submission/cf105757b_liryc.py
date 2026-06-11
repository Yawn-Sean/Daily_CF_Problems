'''
https://codeforces.com/gym/105757/submission/378143467
Math, permutations, primes
'''
MAXN = 2000005
is_prime = [True] * MAXN
is_prime[0] = is_prime[1] = False
for i in range(2, int(MAXN**0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, MAXN, i):
            is_prime[j] = False
next_prime = [0] * MAXN
last_p = -1
for i in range(MAXN - 1, -1, -1):
    if is_prime[i]:
        last_p = i
    next_prime[i] = last_p

def solve(m: int) -> deque[int]:
    if m <= 2:
        return deque(range(1, m + 1))
    p = next_prime[m + 1]
    l, r = p - m, m
    ans = solve(l - 1)
    while l < r:
        ans.appendleft(l)
        ans.append(r)
        l, r, = l + 1, r - 1
    return ans
