import sys
import heapq
input = lambda: sys.stdin.readline().strip()

n, M = map(int, input().split())
ts = list(map(int, input().split()))

pre_s = 0
ans = [0] * n
large_minheap = []
large_heap_sum = 0
small_maxheap = []
small_heap_sum = 0

for i in range(n):
    pre_s += ts[i]
    r = pre_s - M
    if r <= 0:
        ans[i] = 0
    else:
        while large_heap_sum < r:
            x = -heapq.heappop(small_maxheap)
            heapq.heappush(large_minheap, x)
            large_heap_sum += x
        while large_heap_sum - large_minheap[0] >= r:
            large_heap_sum -= large_minheap[0]
            heapq.heappush(small_maxheap, -heapq.heappop(large_minheap))
        ans[i] = len(large_minheap)
    if len(small_maxheap) == 0 or ts[i] <= -small_maxheap[0]:
        heapq.heappush(small_maxheap, -ts[i])
    else:
        heapq.heappush(large_minheap, ts[i])
        large_heap_sum += ts[i]

print(' '.join(map(str,ans)))
