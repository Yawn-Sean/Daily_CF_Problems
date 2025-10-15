n = II()
a = LII()
cnt = Counter(a)
p = [(-cnt[i], i) for i in cnt]
heapify(p)
ans = 0
end = []
k = 10
while len(p) >= 3:
    k -= 1
    ans += 1
    s1, p1 = heappop(p)
    s2, p2 = heappop(p) 
    s3, p3 = heappop(p) 
    s1 += 1
    s2 += 1
    s3 += 1
    if s1:
        heappush(p, (s1, p1))
    if s2:
        heappush(p, (s2, p2))
    if s3:
        heappush(p, (s3, p3))
    end.append(sorted([p1, p2, p3])[::-1])
if ans:
    print(ans)
    for i, j, k in end:
        print(i, j, k)
else:
    print(0)

