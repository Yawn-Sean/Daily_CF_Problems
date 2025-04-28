from collections import deque

n, k = map(int, input().split())
A = list(map(int, input().split()))

if sum(A) < k:
    exit(print(-1))

def check(m):
    s = sum(min(m, a) for a in A)
    return s <= k

left, right = 0, 10**18
while left <= right:
    mid = (left + right) // 2
    if check(mid):
        left = mid + 1
    else:
        right = mid - 1

q = deque()
for i in range(n):
    t = min(right, A[i])
    A[i] -= t
    if A[i] > 0:
        q.append(i)
    k -= t

while k > 0 and q:
    i = q.popleft()
    k -= 1
    A[i] -= 1
    if A[i] > 0:
        q.append(i)

print(*map(lambda x: x + 1, q))
