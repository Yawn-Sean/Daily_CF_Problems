import sys

sys.stdin = open('in.txt', 'r')

n, k, P = map(int, input().split())
a = list(x % P for x in map(int, input().split()))

fmax = lambda x, y: x if x > y else y

pre = 0
f = [[-P * k] * P for _ in range(k + 1)]
f[0][0] = 0

for i in range(n):
    pre = (pre + a[i]) % P

    for j in range(k - 1, -1, -1):
        for x in range(P):
            f[j + 1][pre] = fmax(f[j + 1][pre], f[j][x] + (pre - x) % P)


print(f[k][pre])

'''
f[i][j] 
f[i][j] = max { f[x][j - 1] + sum(x + 1, i) % P }

O(N^2 K)

--- 

f[i][j]
f[i][j] = max { f[P - i][j - 1] + i }

O(NKP)
'''