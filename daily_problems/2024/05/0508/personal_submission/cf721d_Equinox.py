import heapq
import sys

n, k, x = map(int, input().split())
nums = list(map(int, input().split()))

neg = sum(1 for a in nums if a < 0) & 1

if not neg:
    mi = 0
    for i in range(n):
        if abs(nums[i]) < abs(nums[mi]):
            mi = i

    dec = (abs(nums[mi]) - 1) // x + 1

    if k < dec:
        nums[mi] += k * x if nums[mi] < 0 else k * -x
        print(' '.join(map(str, nums)))
        exit()
    if nums[mi] < 0:
        neg = True
    k -= dec
    nums[mi] += dec * x if nums[mi] < 0 else dec * -x

pq = [abs(nums[i]) * n + i for i in range(n)]
heapq.heapify(pq)
for _ in range(k):
    i = heapq.heappop(pq) % n
    if nums[i] == 0 and not neg:
        nums[i] -= x
        neg = True
    else:
        nums[i] += x if nums[i] >= 0 else -x
    heapq.heappush(pq, abs(nums[i]) * n + i)
print(' '.join(map(str, nums)))