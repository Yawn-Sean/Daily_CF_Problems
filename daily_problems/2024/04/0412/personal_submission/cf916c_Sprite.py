prime = 999999937
n, m = map(int, input().split())

ans = ['1 2 %d' %(prime - n+2)]

for i in range(n-2):
    ans.append('%d %d 1' %(i+2, i+3))


i, j = 1, 3
for _ in range(m - n + 1):
    ans.append('%d %d %d' %(i, j, prime))
    j += 1
    if j > n:
        i += 1
        j = i+2
print('%d %d' %(prime, prime))
print('\n'.join(ans))
