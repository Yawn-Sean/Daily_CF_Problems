# Submission link: https://codeforces.com/contest/432/submission/278184180
def main():
    n = II()
    perm = LGMI()

    pos = [-1] * n
    for i in range(n):
        pos[perm[i]] = i

    primes = []
    isPrime = [1] * (n + 1)

    for i in range(2, n + 1):
        if isPrime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                isPrime[j] = 0

    divs = [0] * (n + 1)
    for i in range(4, n + 1, 2):
        for p in primes:
            if isPrime[i-p]:
                divs[i] = p
                break

    def unit_swap(x, y):
        perm[x], perm[y] = perm[y], perm[x]
        pos[perm[x]], pos[perm[y]] = pos[perm[y]], pos[perm[x]]
        ops.append(f'{x + 1} {y + 1}')

    def swap(x, y):
        if isPrime[y-x+1]: unit_swap(x, y)
        elif (y - x) % 2 == 0:
            v = y - x + 2
            unit_swap(x + divs[v] - 1, y)
            unit_swap(x, x + divs[v] - 1)
        else:
            x += 1
            v = y - x + 2
            unit_swap(x + divs[v] - 1, y)
            unit_swap(x, x + divs[v] - 1)
            unit_swap(x - 1, x)

    ops = []
    for i in range(n):
        if pos[i] != i:
            swap(i, pos[i])

    print(len(ops))
    print('\n'.join(ops))