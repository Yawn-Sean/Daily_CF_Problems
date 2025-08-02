"""
预处理素数，预处理最小素因子
对于 + 操作，对 i 进行 O(log n) 的素因数分解，检查是否出现过某种素因子了，需要记录某种素因子的全部来源
对于 - 操作，同样素因数分解，然后从素因子来源中删掉这个来源
"""

n, m = map(int, input().split())

primes = []
min_p = [0 for _ in range(n + 1)]
is_prime = [True for _ in range(n + 1)]

is_prime[1] = False
for i in range(2, n + 1):
    if is_prime[i]:
        primes.append(i)
        min_p[i] = i
    for j in range(len(primes)):
        if i * primes[j] > n:
            break
        is_prime[i * primes[j]] = False
        min_p[i * primes[j]] = primes[j]
        if i % primes[j] == 0:
            break

is_open = [False for _ in range(n + 1)]
factor_from = [set() for _ in range(n + 1)]

def get_factors(val):
    factors = []
    while val > 1:
        p = min_p[val]
        factors.append(p)
        while val % p == 0:
            val //= p
    return factors

while m > 0:
    m -= 1
    op, id = input().split()
    id = int(id)
    if op == '+':
        if is_open[id]:
            print("Already on")
        else:
            factors = get_factors(id)
            has_factor = 0
            for f in factors:
                if len(factor_from[f]) > 0:
                    has_factor = factor_from[f].pop()
                    factor_from[f].add(has_factor)

            if has_factor > 0:
                print(f'Conflict with {has_factor}')
            else:
                is_open[id] = True
                for f in factors:
                    factor_from[f].add(id)
                print('Success')
    else:
        if not is_open[id]:
            print("Already off")
        else:
            is_open[id] = False
            factors = get_factors(id)
            for f in factors:
                factor_from[f].remove(id)
            print('Success')
