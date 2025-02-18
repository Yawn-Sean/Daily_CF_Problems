y, x  = map(int, input().split())
cur = [x, x, x]
ans = 0
while cur != [y, y, y]:
    ans += 1
    cur[0] = min(cur[1] + cur[2] - 1, y)
    cur.sort()
print(ans)
