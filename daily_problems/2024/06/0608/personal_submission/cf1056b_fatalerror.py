n, m = map(int, input().split())
cnt = [0] * m
for r in range(m):
    cnt[r*r%m] += n//m + (0 < r <= n%m)
ans = sum(cnt[r] * cnt[(-r)%m] for r in range(m))
print(ans)