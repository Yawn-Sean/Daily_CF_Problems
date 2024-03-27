import heapq
import sys

input = sys.stdin.readline
n = int(input())
a = [0] * n
b = []
for _ in range(2 * n):
    b.append(input().rstrip())

q = []
p = n - 1
pre = float('inf')
for i in range(2 * n - 1, -1, -1):
    if b[i][0] == '-':
        v = int(b[i].split()[1])
        if v > pre:
            print("NO")
            exit(0)
        pre = v
        heapq.heappush(q, v)
    else:
        pre = float('inf')
        if len(q) == 0:
            print("NO")
            exit(0)
        else:
            a[p] = heapq.heappop(q)
            p -= 1

p = 0
for i in range(0, 2 * n):
    if b[i][0] == '-':
        v = int(b[i].split()[1])
        if heapq.heappop(q) != v:
            print("NO")
            exit(0)
    else:
        heapq.heappush(q, a[p])
        p += 1

print("YES")
print(*a)
