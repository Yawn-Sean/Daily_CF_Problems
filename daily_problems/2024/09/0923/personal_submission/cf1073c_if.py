n = int(input())
s = input()
x, y = map(int, input().split())
dx, dy = [0 for _ in range(n)], [0 for _ in range(n)]
xx, yy = 0, 0
for i in range(n):
    if s[i] == 'U':
        dy[i] = 1
    if s[i] == 'D':
        dy[i] = -1
    if s[i] == 'L':
        dx[i] = -1
    if s[i] == 'R':
        dx[i] = 1
for i in range(n):
    xx += dx[i]
    yy += dy[i]
if (x + y + n) % 2 != 0 or abs(x) + abs(y) > n:
    print(-1)
elif xx == x and yy == y:
    print(0)
else:
    l = 0
    ans = n
    for r in range(n):
        xx -= dx[r]
        yy -= dy[r]
        while abs(xx - x) + abs(yy - y) <= r - l + 1:
            xx += dx[l]
            yy += dy[l]
            l += 1
        if l > 0:
            ans = min(ans, r - l + 2)
    print(ans)
