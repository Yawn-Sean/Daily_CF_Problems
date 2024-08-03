from heapq import heappop, heappush
n = int(input())
a = list(map(int, input().split()))
t = list(map(int, input().split()))

add_t = []
ans = 0
empty = 0
all_t = 0
k = sorted(range(n), key = lambda x: a[x])
for now in k:
    while add_t and last < a[now]:
        x = heappop(add_t)
        all_t += x
        ans += all_t
        last += 1
    heappush(add_t, -t[now])
    last = a[now]
    all_t += t[now]

while add_t:
    x = heappop(add_t)
    all_t += x
    ans += all_t

print(ans)
