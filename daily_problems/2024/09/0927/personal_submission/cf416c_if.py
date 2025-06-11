import heapq
s = []
n = int(input())
for i in range(n):
    c1, p1 = map(int, input().split())
    s.append([-p1, i + 1, c1])
s.sort(key = lambda x: -x[-1])
k = int(input())
r = list(map(int, input().split()))
for i in range(k):
    r[i] = [r[i], i + 1]
r.sort()
p = []
ans = []
cur = 1
cnt = 0
for i in r:
    while s and s[-1][-1] <= i[0]:
        heapq.heappush(p, s[-1])
        s.pop()
    if p:
        tar = heapq.heappop(p)
        cnt -= tar[0]
        ans.append([tar[1], i[1]])
print(len(ans), cnt)
ans.sort(key = lambda x: x[-1])
for i in ans:
    print(*i)

