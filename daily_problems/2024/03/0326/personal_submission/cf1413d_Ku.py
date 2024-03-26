import sys
from heapq import *
input = lambda :sys.stdin.readline().rstrip()   #快速输入
n = int(input())
li = [input() for _ in range(2 * n)]
ans = [-1] * (2*n)
stack = []
for i in range(2 * n):
    if li[i] == '+':
        stack.append(i)
    else:
        v = int(li[i].split()[1])
        if len(stack) == 0:
            print('NO')
            exit()
        ans[stack.pop()] = v

hep = []
for i in range(n * 2):
    if li[i] == '+':
        heappush(hep,ans[i])
    else:
        v = int(li[i].split()[1])
        if heappop(hep) != v:
            print('NO')
            exit()
print('YES')
print(' '.join(str(x) for x in ans if x != -1))
