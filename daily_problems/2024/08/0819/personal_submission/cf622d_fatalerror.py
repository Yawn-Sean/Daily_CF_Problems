n = int(input())
ans = [0] * (n*2)
for x in range(n):
    p1 = x//2 + (n if x & 1 else 0)
    p2 = p1 + n - 1 - x
    ans[p1] = ans[p2] = x + 1
ans[-1] = n
print(*ans)