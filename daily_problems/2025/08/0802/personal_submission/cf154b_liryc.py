'''
https://codeforces.com/problemset/submission/154/332024780
'''
# primes
prime_factors = []
def initPrimes(n: int):
    global prime_factors
    prime_factors = list(range(n + 1))
    limit = int(n ** 0.5) + 1
    for i in range(2, limit):
        if prime_factors[i] == i:
            for j in range(i + i, n + 1, i):
                prime_factors[j] = i

def prime_elements(n: int):
    global prime_factors
    a = []
    while (f := prime_factors[n]) != n:
        if not a or a[-1] != f:
            a.append(f)
        n //= f
    if not a or a[-1] != n:
        a.append(n)
    return a

es = []
vis = []
def request(op: str, n: int) -> str:
    global es, vis
    if (op == '+') == vis[n]:
        return f"Already {'on' if vis[n] else 'off'}"

    if op == '-':
        for p in prime_elements(n):
            es[p] = 0
    elif n > 1:
        pa = prime_elements(n)
        for p in pa:
            if es[p]:
                return f"Conflict with {es[p]}"
        for p in pa:
            es[p] = n

    vis[n] = not vis[n]
    return "Success"

if __name__ == '__main__':
    n, m = map(int, input().split())
    es = [0] * (n + 1)
    vis = [False] * (n + 1)
    initPrimes(n)
    for _ in range(m):
        ra = input().split()
        print(request(ra[0], int(ra[1])))
