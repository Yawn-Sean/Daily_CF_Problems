from collections import deque


n, m = map(int, input().split())
m -= 1
res = deque()
res.append(n)
for i in range(n - 1, 0, -1):
    if m % 2:
        res.append(i)
    else:
        res.appendleft(i)
    m >>= 1
print(' '.join(map(str, res)))
