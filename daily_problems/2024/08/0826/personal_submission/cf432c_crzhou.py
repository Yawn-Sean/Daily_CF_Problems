# 埃式筛
MX = 10 ** 5 + 1
primes = []
is_prime = [True] * MX
for i in range(2, MX):
    if is_prime[i]:
        primes.append(i)
        for j in range(i*i, MX, i):  # i**2 小优化
            is_prime[j] = False

d = defaultdict(int)
n = II()
nums = LGMI()
for i in range(n):
    d[nums[i]] = i

outs = []
for i in range(n):
    if nums[i] != i:
        tmp = d[i] - i
        while tmp > 0:
            tmp += 1
            if is_prime[tmp]:
                a = tmp - 1
                tmp = 0
                j = i
                jj = nums[i]
                nums[d[i]], nums[i] = jj, nums[d[i]]
                d[jj] += a
                d[i] -= a
                outs.append((j + 1, j + a + 1))
            else:
                a = primes[bisect_left(primes, tmp) - 1] - 1
                j = d[i] - a
                jj = nums[j]
                nums[d[i]], nums[j] = jj, nums[d[i]]
                d[jj] += a
                d[i] -= a
                outs.append((j + 1, j + a + 1))
                tmp -= a + 1
            
print(len(outs))
print('\n'.join(' '.join(map(str, x)) for x in outs))
