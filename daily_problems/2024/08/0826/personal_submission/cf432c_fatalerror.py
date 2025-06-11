n = int(input())
arr = [0] + list(map(int, input().split()))
mp = [0] * (n+1)
for i, x in enumerate(arr):
    mp[x] = i

isprime = [True] * (n+1)
isprime[0] = isprime[1] = False
primes = []
for num in range(2, n+1):
    if isprime[num]:
        primes.append(num)
    for p in primes:
        if num * p > n:
            break
        isprime[num * p] = False
        if num % p == 0:
            break

maxp = [1] * (n+1)
p = 2
for x in range(2, n+1):
    if isprime[x]:
        p = x
    maxp[x] = p

ans = []
for x in range(1, n+1):
    while (i := mp[x]) != x:
        j = i - maxp[i-x+1] + 1
        y = arr[j]
        ans.append(f'{j} {i}')
        arr[i], arr[j] = arr[j], arr[i]
        mp[x], mp[y] = mp[y], mp[x]

print(len(ans))
print(*ans, sep='\n')