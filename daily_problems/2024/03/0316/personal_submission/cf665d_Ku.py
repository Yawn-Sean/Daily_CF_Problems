isPrime = [1] * (2 * 10 ** 6 + 1)
isPrime[0] = isPrime[1] = 0
for i in range(2, 2 * 10 ** 6 + 1):
    if isPrime[i]:
        for j in range(i * i, 2 * 10 ** 6 + 1, i):
            isPrime[j] = 0
ans = []
n = int(input())
a = list(map(int,input().split()))

odd, even = [], []
my = 0
for i,x in enumerate(a):
    if x % 2 == 0:
        even.append(x)
    else:
        if x == 1:
            my += 1
        odd.append(x)

cnt_even = set(even)
cnt_odd = set(odd)
if my:
    ans = [1] * my
    for x in cnt_even:
        if my and isPrime[x+1]:
            ans = [1] * my + [x]

if len(ans) <= 1:
    for x in cnt_even:
        for y in cnt_odd:
            if isPrime[x + y]:
                ans = [x] + [y]

if len(ans) == 0:
    ans = [a[0]]
print(len(ans))
strNums = [str(x) for x in ans]
print(' '.join(strNums))
