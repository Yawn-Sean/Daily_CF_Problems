from collections import *

n, x, y = map(int, input().split())
arr = []
c = Counter()
for i in range(1, x + 1):
    arr.append((i * y, 0))
    c[i * y] += 1
for j in range(1, y + 1):
    arr.append((j * x, 1))
    c[j * x] += 1
arr.sort()
res = ['Vanya', 'Vova']
for _ in range(n):
    t = int(input())
    if t % (x + y) == 0:
        print('Both' + '\n')
        continue
    if t > x + y:
        t = t % (x + y)
    ans = arr[t - 1]
    if c[ans[0]] == 1:
        print(res[ans[1]] + '\n')
    else:
        print('Both' + '\n')
####
